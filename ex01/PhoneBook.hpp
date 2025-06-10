/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 05:18:15 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 17:26:46 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define MAX_CONTACTS 8
#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>

class PhoneBook {
private:
    Contact _contacts[MAX_CONTACTS];
    int _currentCount;
    int _oldestContactIndex;
    std::string _truncateField(const std::string &s) const;
    bool _promptNonEmptyInput(const std::string &prompt, std::string &output);
    bool _handleInputError(void);

public:
    PhoneBook(void);
    void addContact(const Contact &newContact);
    void displayContact(void) const;
    void searchContact(void) const;
    void promptAddContact(void);
};

#endif // !PHONEBOOK_HPP
