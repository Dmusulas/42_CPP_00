/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:44:24 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/27 05:37:40 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    if (argc > 1) {
        for (int i = 1; i < argc; ++i)

        {
            std::string s = argv[i];
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            std::cout << s;
        }
        std::cout << std::endl;
    }
}
