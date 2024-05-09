/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:44:44 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/09 09:24:52 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* This means that the caller gets a reference to _type (avoiding a copy),
but they can't use this reference to modify _type, because it's const.
If _type is a private member of the Weapon class,
this is a common and safe way to provide read-only access to it from outside the class.
The callers can see the value of _type, but they can't change it.

passing type as a const reference because then the function doesn't need to make a copy of the value of type.
however, when assigning it to _type it will still make a copy.
*/


Weapon::Weapon(const std::string& type)
{
	_type = type;
}

const std::string& Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(const std::string& type)
{
	_type = type;
}
