/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:33:14 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/27 11:00:23 by dmusulas         ###   ########.fr       */
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

int main() {
    PhoneBook phoneBook;
    std::string input;

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

    return (0);
}
