/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:20:53 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 15:31:03 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
PhoneBook::PhoneBook() : count(0), next(0) {}

PhoneBook::~PhoneBook(void) {}

bool	ifDigits(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (std::isdigit(str[i]))
			return (true);
	}
	return (false);
}

bool	ifValidNumber(const std::string& str)
{
	if (str.length() != 10)
		return (false);
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit((str[i])))
			return (false);
	}
	return (true);
}

static std::string trim(const std::string& str)
{
	std::string s = str;

	std::string::size_type start = 0;
	while (start < s.length() && std::isspace((s[start])))
		start++;
	std::string::size_type end = s.length();
	while (end > start && std::isspace((s[end - 1])))
		end--;
	return s.substr(start, end - start);
}

void	PhoneBook::addContact(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	
	while (true)
	{
		std::cout << "Enter the first name :";
		if (!std::getline (std::cin, firstName))
			return ;
		firstName = trim(firstName);
		if (firstName.empty())
		{
			std::cout << "It must not be empty" << std::endl;
			continue ;
		}
		if (ifDigits(firstName))
		{
			std::cout << "It must not contain digits!" << std::endl;
			continue ;
		}
		break ;
	}

	while (true)
	{
		std::cout << "Enter the last name :";
		if (!std::getline (std::cin, lastName))
			return ;
		lastName = trim(lastName);
		if (lastName.empty())
		{
			std::cout << "It must not be empty" << std::endl;
			continue ;
		}
		if (ifDigits(lastName))
		{
			std::cout << "It must not contain digits!" << std::endl;
			continue ;
		}
		break ;
	}

	while (true)
	{
		std::cout << "Enter the nickname :";
		if (!std::getline (std::cin, nickname))
			return ;
		nickname = trim(nickname);
		if (nickname.empty())
		{
			std::cout << "It must not be empty" << std::endl;
			continue ;
		}
		if (ifDigits(nickname))
		{
			std::cout << "It must not contain digits!" << std::endl;
			continue ;
		}
		break ;
	}

	while (true)
	{
		std::cout << "Enter the phone number :";
		if (!std::getline (std::cin, phoneNumber))
			return ;
		phoneNumber = trim(phoneNumber);
		if (phoneNumber.empty())
		{
			std::cout << "It must not be empty" << std::endl;
			continue ;
		}
		if (!ifValidNumber(phoneNumber))
		{
			std::cout << "Phone number must contain 10 digits!" << std::endl;
			continue ;
		}
		break ;
	}

	while (true)
	{
		std::cout << "Enter the secret :";
		if (!std::getline (std::cin, darkestSecret))
			return ;
		darkestSecret = trim(darkestSecret);
		if (darkestSecret.empty())
		{
			std::cout << "It must not be empty" << std::endl;
			continue ;
		}
		break ;
	}

	contacts[next].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	if (count < 8)
		count++;
	next = (next + 1) % 8;
	std::cout << "The contact has been added successfully" << std::endl;
}

std::string	truncString(std::string str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

//SEARCH
void	PhoneBook::displayContacts(void) const
{
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|" 
				<< std::setw(10) << truncString(contacts[i].getFirstName()) << "|"
				<< std::setw(10) << truncString(contacts[i].getLastName()) << "|"
				<< std::setw(10) << truncString(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void	PhoneBook::displayDetailsContacts(int i) const
{
	std::cout << "First name is :" << contacts[i].getFirstName() << std::endl;
	std::cout << "Last name is :" << contacts[i].getLastName() << std::endl;
	std::cout << "Nickname is :" << contacts[i].getNickname() << std::endl;
	std::cout << "Phone number is :" << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret is :" << contacts[i].getDarkestSecret() << std::endl;
}

void	PhoneBook::search(void)
{
	std::string 	number;
	int				i;

	displayContacts();

	std::cout << "Enter the contact number to display :";
	std::getline(std::cin, number);
	if (number.length() == 1 && std::isdigit(number[0]))
	{
		i = number[0] - '0';
		if (i >= 0 && i < count)
			displayDetailsContacts(i);
		else
			std::cout << "This number of contact doesn't exist" << std::endl;
	}
	else
		std::cout << "The number must be between 0 and 7" << std::endl;
}
