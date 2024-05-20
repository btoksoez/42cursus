/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:37:21 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 13:43:21 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_numContacts = 0;
}

void	PhoneBook::add(Contact new_contact)
{
	static int	i = 0;

	this->_contacts[i % 8] = new_contact;
	this->_contacts[i % 8].setIndex(i % 8);
	if (_numContacts < 8)
		_numContacts++;
	i++;
}

void PhoneBook::_printHeader(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|--------- PhoneBook: All Entries ----------|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First";
	std::cout << "|" << std::setw(10) << "Last";
	std::cout << "|" << std::setw(10) << "Nick";
	std::cout << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	PhoneBook::show_all(void)
{
	int	i = 0;
	_printHeader();
	if (_numContacts == 0)
	{
		std::cout << "|           No contacts saved yet           |\n";
	}
	else
	{
		while (i < _numContacts)
			this->_contacts[i++].show();
	}
	std::cout << "|-------------------------------------------|\n\n\n";
}

void	PhoneBook::show_entry(void)
{
	int index;

	std::string str = getInputNum("Choose entry to see: ");
	index = ft_atoi(str.c_str());
	if (index >= _numContacts || std::cin.fail())
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|            Entry doesn't exist            |" << std::endl;
		std::cout << "|-------------------------------------------|\n\n\n";
		return ;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|------------ Showing Entry: " << index << " -------------|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|" << "Index: " << index << std::endl;
	std::cout << "|" << "First: " << _contacts[index].getFirst() << std::endl;
	std::cout << "|" << "Last: " << _contacts[index].getLast() << std::endl;
	std::cout << "|" << "Nick: " << _contacts[index].getNick() << std::endl;
	std::cout << "|" << "Number: " << _contacts[index].getNum() << std::endl;
	std::cout << "|" << "Secret: " << _contacts[index].getSecret() << std::endl;
	std::cout << "|-------------------------------------------|\n\n\n";
}



