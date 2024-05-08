/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:37:21 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 14:32:17 by btoksoez         ###   ########.fr       */
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
	//validate input, reprompt
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|------------ Showing Entry: " << index << " -------------|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First";
	std::cout << "|" << std::setw(10) << "Last";
	std::cout << "|" << std::setw(10) << "Nick";
	std::cout << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	this->_contacts[index].show();
	std::cout << "|-------------------------------------------|\n\n\n";
}



