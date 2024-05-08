/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:22:42 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 12:22:53 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* This function creates a new Zombie object on the stack.
 * Allocating an object on the stack means that the memory for the object is automatically
 * allocated and deallocated by the program during function execution.
 * The Zombie object created by this function will be destroyed and deallocated
 * when the function returns.
 */
void	randomChump(std::string name)
{
	Zombie	z(name);

	z.announce();
}
