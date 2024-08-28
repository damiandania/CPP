/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:27 by ddania-c          #+#    #+#             */
/*   Updated: 2024/02/21 10:58:28 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.class.hpp"
#include <iostream>
#include <string>


class PhoneBook {
	private:
		int 		_index;
		Contact		_contactList[8];

		std::string	_getInput(std::string message);
		void		_nextIndex();
		void		_showContactList();
		void		_printContact(int i);
		void		_printData(std::string data);
		void		_showContactInfo(std::string input);

	public:
		PhoneBook();
		~PhoneBook();

		bool		addContact();
		void		showContact();
		bool		seachContact();
		std::string	trimSpaces(std::string input);
};

#endif
