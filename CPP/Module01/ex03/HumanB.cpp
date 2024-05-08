/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:04:29 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 15:31:16 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}
void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
