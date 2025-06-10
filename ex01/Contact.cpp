/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 06:40:17 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 17:26:43 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(const std::string &fn, const std::string &ln,
                 const std::string &nn, const std::string &pn,
                 const std::string &ds)
    : firstName(fn), lastName(ln), nickName(nn), phoneNumber(pn),
      darkestSecret(ds) {
    if (firstName.empty() || lastName.empty() || nickName.empty() ||
        phoneNumber.empty() || darkestSecret.empty()) {
        throw std::invalid_argument("Error: Contact fields cannot be empty.");
    }
}

// Getters
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickName; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
