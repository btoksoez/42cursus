/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:23:12 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/07 12:20:53 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	isWhitespace(const std::string& str)
{
	return (str.find_first_not_of(" \t\n") == std::string::npos);
}

std::string	trim(std::string& str)
{
	size_t	start = str.find_first_not_of(" \t\n");
	size_t	end = str.find_last_not_of(" \t\n");
	return (str.substr(start, end - start + 1));
}

std::string getInput(std::string str)
{
    std::string input = "";
    bool        valid = false;

    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty() && !isWhitespace(input))
            valid = true;
        else {
            std::cin.clear();
        }
    } while (!valid);
    return (trim(input));
}

std::string	getInputNum(std::string str)
{
    std::string input = "";
    bool        valid = false;

    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty() && !isWhitespace(input) && isDigitStr(input))
            valid = true;
        else
		{
            std::cin.clear();
		}
    } while (!valid);
    return (trim(input));
}

bool	isDigitStr(std::string str)
{
	unsigned long	i = 0;

	str = trim(str);
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
int	ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (sign * result);
}
