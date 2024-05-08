/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:22:03 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 12:22:13 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* This function creates a new Zombie object on the heap and returns a pointer to it.
 * Allocating an object on the heap means that the memory for the object is dynamically
 * allocated during runtime and must be manually deallocated to avoid memory leaks.
 * The caller is responsible for managing the memory of the returned Zombie object.
 */
Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}
