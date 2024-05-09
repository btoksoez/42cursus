/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:28:15 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/09 14:35:07 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

bool	check_args(char *argv[])
{
	//needs to check that argv[1] is an accessable file
	if (access(argv[1], F_OK) == -1)
	{
		std::cout << "Invalid File" << std::endl;
		return (false);
	}
	if (access(argv[1], R_OK) == -1)
	{
		std::cout << "Invalid Permissions" << std::endl;
		return (false);
	}
	//s1 and s2 are strings
	if (argv[2][0] == '\0')
	{
		std::cout << "Empty String" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cout << "Usage: ./replace <filename> <string to replace> <replacing string>" << std::endl, 1);
	if (!check_args(argv))
		return (1);
	FileHandler f(argv[3], argv[2]);
	if (!f.openFiles(argv[1]))
		return (1);
	f.replaceLines();
}
