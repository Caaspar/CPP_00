/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:25:58 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 15:31:35 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	std::cout << "Welcome to the PhoneBook ! ✨​" << std::endl;
	while (1)
	{
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (cmd == "EXIT")
		{
			std::cout << "Closing the PhoneBook..." << std::endl;
			break ;
		}
		else
			std::cout << "Wrong command ! Try ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}