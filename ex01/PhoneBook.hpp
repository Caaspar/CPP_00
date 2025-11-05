/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:52:42 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 15:36:16 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contacts[8];
		int		count;
		int		next;

	public:
		PhoneBook();
		void	addContact(void); //ADD
		void	displayContacts() const; //SEARCH
		void	displayDetailsContacts(int i) const; //SEARCH
		void	search(void);
		~PhoneBook();
};

#endif