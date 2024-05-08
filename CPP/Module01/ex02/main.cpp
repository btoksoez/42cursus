/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:21:16 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/08 14:34:36 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
The primary use of references is for function argument passing.
When you pass a variable by reference, the function operates on the original data, not a copy.
This allows the function to modify the argument, and it avoids the overhead of copying large data structures.

References are safer and easier to use than pointers.
They always refer to a valid object (they cannot be null),
they cannot be reassigned to refer to a different object,
and there's no need to worry about memory management.
*/
int main(void)
{
	std::string str = "HI THIS IS BRIAN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of the string variable: " << &str << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "value of the string variable: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;

}
