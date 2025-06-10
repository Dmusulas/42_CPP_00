/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:44:24 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/10 17:16:56 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            std::string s = argv[i];
            for (size_t j = 0; j < s.length(); ++j) {
                s[j] = std::toupper(s[j]);
            }
            std::cout << s;
        }
        std::cout << std::endl;
    }
    return 0;
}
