/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:06:13 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/27 06:40:05 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {

private:
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

public:
    Contact(void) {} // default constructor for array
    Contact(const std::string &fn, const std::string &ln, const std::string &nn,
            const std::string &pn, const std::string &ds);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif // !CONTACT_HPP
