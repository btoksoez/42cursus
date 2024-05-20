/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:34:44 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 13:27:59 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ---------- constructors ------------ */

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.getX()), y(other.getY()) {}

Point::~Point() {}


/* -------- assignment operator --------- */

/* this doesn;t work */
Point &Point::operator=(const Point &other)
{
	// std::cout << "Point Assignation operator called" << std::endl;
	if (this == &other)
		return *this;

	/*CODE*/
	return *this;
}

/* -------- getter functions --------- */

Fixed	Point::getX( void ) const
{
	return (this->x);
}

Fixed	Point::getY( void ) const
{
	return (this->y);
}

/* -------- printing --------- */

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")" << std::endl;
	return (os);
}
