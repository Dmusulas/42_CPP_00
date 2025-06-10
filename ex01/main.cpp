/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:33:14 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 18:02:27 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

enum Command { ADD, SEARCH, EXIT, INVALID };

Command parseCommand(const std::string &input) {
    if (input == "ADD")
        return ADD;
    if (input == "SEARCH")
        return SEARCH;
    if (input == "EXIT")
        return EXIT;
    return INVALID;
}

// TEST:: lazy to come up with names randomization func
// std::string randomString(const std::string &chars, size_t length) {
//     std::string result;
//     for (size_t i = 0; i < length; ++i) {
//         result += chars[rand() % chars.size()];
//     }
//     return result;
// }

int main() {
    std::string input;
    PhoneBook phoneBook;

    // TEST:: to check if index wraps with ADD
    // std::srand(time(NULL));
    // const std::string letters = "abcdefghijklmnopqrstuvwxyz";
    // const std::string digits = "0123456789";
    // for (int i = 0; i < 8; ++i) {
    //     std::string firstName = randomString(letters, 5);
    //     std::string lastName = randomString(letters, 7);
    //     std::string nickname = randomString(letters, 6);
    //     std::string phoneNumber = randomString(digits, 10);
    //     std::string darkSecret = randomString(letters, 20);
    //     Contact newContact(firstName, lastName, nickname, phoneNumber,
    //                        darkSecret);
    //     phoneBook.addContact(newContact);
    // }

    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    while (std::getline(std::cin, input)) {
        Command command = parseCommand(input);

        switch (command) {
        case ADD:
            phoneBook.promptAddContact();
            break;
        case SEARCH:
            phoneBook.searchContact();
            break;
        case EXIT:
            std::cout << "Exiting phonebook. Goodbye!\n";
            return 0;
        case INVALID:
            std::cout << "Invalid command. Try again.\n";
            break;
        }
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    }

    if (std::cin.bad()) {
        std::cerr << "Fatal error: Input stream is corrupted.\n";
        return (EXIT_FAILURE);
    } else if (std::cin.eof()) {
        std::cout << "\nEOF detected. Exiting phonebook. Goodbye!\n";
        return (EXIT_SUCCESS);
    } else {
        std::cerr << "Unexpected error: Input stream failed.\n";
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
