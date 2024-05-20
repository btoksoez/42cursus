/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:00:33 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 14:17:38 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]:\n I love having extra bacon....\n" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]:\n I cannot believe adding extra bacon ...\n" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]:\n I think I deserve to have some ...\n" << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]:\n This is unacceptable! ...\n" << std::endl;
}

/* will "enter" code at case which is true and then execute the rest unless there are break statements */
void	Harl::harlFilter(int level)
{
	switch (level)
	{
		case 0:
			debug();
			//fall through
		case 1:
			info();
			//fall through
		case 2:
			warning();
			//fall through
		case 3:
			error();
			//fall through
	}
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		i = 0;

	while (i < 4)
	{
		if (levels[i] == level)
		{
			harlFilter(i);
			return ;
		}
		i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

