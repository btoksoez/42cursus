/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:20:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/10 11:43:28 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
		return (std::cout << "Usage: ./harlFilter <level>" << std::endl, 1);
	harl.complain(argv[1]);
}
