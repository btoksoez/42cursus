/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:25:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 14:09:17 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** This function creates a horde of zombies by dynamically allocating an array of Zombie objects.
** The function takes two parameters: N, the number of zombies to create, and name, the name to assign to each zombie.
** It returns a pointer to the first element of the array.
** The function first allocates memory for N Zombie objects using the new[] operator
** and then also calls the default constructor for each of them!
** Then, it iterates over the array and sets the name of each zombie using the setName() method.
** Finally, it returns the pointer to the first element of the array.
*/
Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;
	int i = 0;

	horde = new Zombie[N];
	while (i < N)
		horde[i++].setName(name);
	return horde;
}
