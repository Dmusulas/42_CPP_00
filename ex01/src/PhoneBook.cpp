/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 06:56:36 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 17:31:36 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void) : _currentCount(0), _oldestContactIndex(0) {}

bool PhoneBook::_handleInputError(void) {
    if (std::cin.eof()) {
        std::cout << "\nEOF detected. Exiting phonebook. Goodbye!\n";
        std::exit(0);
    } else if (std::cin.bad()) {
        std::cerr << "Fatal error: Input stream is corrupted.\n";
        std::exit(1);
    } else {
        std::cerr << "Unexpected error: Input stream failed.\n";
        return false;
    }
}

bool PhoneBook::_promptNonEmptyInput(const std::string &prompt,
                                     std::string &output) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, output)) {
            return _handleInputError();
        }
        if (!output.empty()) {
            return true;
        }
        std::cout << "Error: Field cannot be empty.\n";
        std::cout << "Try again? [Y/N]: ";
        std::string retry;
        if (!std::getline(std::cin, retry)) {
            return _handleInputError();
        }
        for (size_t i = 0; i < retry.length(); ++i) {
            retry[i] = std::toupper(retry[i]);
        }
        if (retry != "Y") {
            return false;
        }
    }
}

void PhoneBook::addContact(const Contact &newContact) {
    if (_currentCount < MAX_CONTACTS) {
        _contacts[_currentCount] = newContact;
        _currentCount++;
    } else {
        _contacts[_oldestContactIndex] = newContact;
        _oldestContactIndex = (_oldestContactIndex + 1) % MAX_CONTACTS;
    }
}

std::string PhoneBook::_truncateField(const std::string &s) const {
    if (s.length() > 10) {
        return s.substr(0, 9) + ".";
    }
    return s;
}

void PhoneBook::displayContact(void) const {

    std::cout << std::setw(10) << "Index"
              << " | ";
    std::cout << std::setw(10) << "First Name"
              << " | ";
    std::cout << std::setw(10) << "Last Name"
              << " | ";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < _currentCount; i++) {
        std::cout << std::setw(10) << i << " | ";
        std::cout << std::setw(10)
                  << _truncateField(_contacts[i].getFirstName()) << " | ";
        std::cout << std::setw(10) << _truncateField(_contacts[i].getLastName())
                  << " | ";
        std::cout << std::setw(10) << _truncateField(_contacts[i].getNickName())
                  << std::endl;
    }
};

void PhoneBook::promptAddContact() {
    std::string fn, ln, nn, pn, ds;

    std::cout << "Adding a new contact:\n";
    if (!_promptNonEmptyInput("First name: ", fn) ||
        !_promptNonEmptyInput("Last name: ", ln) ||
        !_promptNonEmptyInput("Nickname: ", nn) ||
        !_promptNonEmptyInput("Phone number: ", pn) ||
        !_promptNonEmptyInput("Darkest secret: ", ds)) {
        std::cout << "Input cancelled. Returning to main menu.\n";
        return;
    }

    try {
        Contact newContact(fn, ln, nn, pn, ds);
        addContact(newContact);
        std::cout << "Contact added successfully!\n";
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}

void PhoneBook::searchContact() const {
    displayContact();

    std::string input;
    std::cout << "Enter index: ";
    std::getline(std::cin, input);

    int index = -1;
    std::istringstream iss(input);
    if (!(iss >> index) || !iss.eof()) {
        std::cout << "Invalid index.\n";
        return;
    }

    if (index < 0 || index >= _currentCount) {
        std::cout << "Index out of range.\n";
        return;
    }

    const Contact &contact = _contacts[index];

    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
