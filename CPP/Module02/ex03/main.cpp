/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:16:04 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 13:25:23 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point p1(-1, -1);
    Point p2(2, 3);
    Point p3(3, -3);
    Point p4(-0.008, -0.008);
    Point p5(3, 3);

    std::cout << "Points:\n";
    std::cout << "p1: " << p1;
    std::cout << "p2: " << p2;
    std::cout << "p3: " << p3;
    std::cout << "p4: " << p4;
    std::cout << "p5: " << p5 << std::endl;

	std::cout << "P4 is in triangle: " << bsp(p1, p2, p3, p4) << std::endl;
	std::cout << "P5 is in triangle: " << bsp(p1, p2, p3, p5) << std::endl;

    return 0;
}
