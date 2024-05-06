/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:11:35 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/06 14:23:57 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

/* returns true if string contains only whitespace */
bool Contact::_isWhitespace(const std::string& str)
{
	return (str.find_first_not_of(" \t\n") == std::string::npos);
}

std::string	Contact::_trim(std::string& str)
{
	size_t	start = str.find_first_not_of(" \t\n");
	size_t	end = str.find_last_not_of(" \t\n");
	return (str.substr(start, end - start + 1));
}

std::string Contact::_getInput(std::string str)
{
    std::string input = "";
    bool        valid = false;

    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty() && !_isWhitespace(input))
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (_trim(input));
}

bool	Contact::_isDigitStr(std::string str)
{
	unsigned long	i = 0;

	str = _trim(str);
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

std::string Contact::_getInputNum(std::string str)
{
    std::string input = "";
    bool        valid = false;

    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty() && !_isWhitespace(input) && _isDigitStr(input))
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (_trim(input));
}

void	Contact::setIndex(int i)
{
	this->_index = i;
}

/* gets input for each field, checks if its valid and trims it and saves it to the right field*/
void	Contact::create_new(void)
{
    std::cin.ignore();
    this->_first = this->_getInput("Please enter you first name: ");
    this->_last = this->_getInput("Please enter your last name: ");
    this->_nick = this->_getInput("Please enter your nickname: ");
    this->_num = this->_getInputNum("Please enter your phone number: ");
    this->_secret = this->_getInput("Please enter your darkest secret: ");
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
