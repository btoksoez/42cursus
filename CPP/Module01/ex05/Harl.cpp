/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:00:33 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/10 11:34:19 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon...." << std::endl;
}
void	Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon ..." << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some ..." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! ..." << std::endl;
}

void	Harl::complain(std::string level)
{
	LevelFunction	levelfunction[] =
	{
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	int				i = 0;

	while (i < 4)
	{
		if (levelfunction[i].level == level)
		{
			(this->*levelfunction[i].func)();
			return ;
		}
		i++;
	}
	std::cout << "No such level" << std::endl;
}

