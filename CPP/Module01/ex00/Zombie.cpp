/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:54:04 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 13:58:40 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << "Destroying Zombie " << _name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name;
	std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}
