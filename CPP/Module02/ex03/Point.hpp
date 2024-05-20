/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:31:49 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 12:44:20 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
# define POINT_HPP_

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();

		Point&	operator=(const Point& other);

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

		friend std::ostream& operator<<(std::ostream& os, const Point& point);

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
