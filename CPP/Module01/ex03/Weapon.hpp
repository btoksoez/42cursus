/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:38:12 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/09 09:25:07 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

/* a const reference is useful when you want to provide access to a member variable,
but you don't want to allow it to be modified.
It also avoids making a copy of the string, which can be more efficient if the string is large.
*/
class Weapon
{
	private:
		std::string			_type;
	public:
		Weapon(const std::string& type);
		const std::string&	getType(void);
		void				setType(const std::string& type);
};

#endif
