/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:34:44 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/16 13:53:24 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ---------- constructors ------------ */

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}


/* -------- assignment operator --------- */

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}
