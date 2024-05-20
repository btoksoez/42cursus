/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:11:35 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 13:39:03 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setIndex(int i)
{
	this->_index = i;
}

/* gets input for each field, checks if its valid and trims it and saves it to the right field*/
void	Contact::create_new(void)
{
    this->_first = getInput("Please enter you first name: ");
    this->_last = getInput("Please enter your last name: ");
    this->_nick = getInput("Please enter your nickname: ");
    this->_num = getInputNum("Please enter your phone number: ");
    this->_secret = getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

std::string	Contact::_printLen(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::show(void)
{
	std::cout << "|" << std::setw(10) << this->_index;
	std::cout << "|" << std::setw(10) << _printLen(this->_first);
	std::cout << "|" << std::setw(10) << _printLen(this->_last);
	std::cout << "|" << std::setw(10) << _printLen(this->_nick);
	std::cout << "|" << std::endl;
}

const std::string& Contact::getFirst()
{
	return (this->_first);
}

const std::string& Contact::getLast()
{
	return (this->_last);
}

const std::string& Contact::getNick()
{
	return (this->_nick);
}

const std::string& Contact::getNum()
{
	return (this->_num);
}

const std::string& Contact::getSecret()
{
	return (this->_secret);
}
