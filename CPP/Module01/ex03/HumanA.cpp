/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:04:29 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/09 09:16:15 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	_weapon = &weapon;
	_name = name;
}
void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
