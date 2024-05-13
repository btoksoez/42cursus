/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:30:02 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/12 07:53:53 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* -------- constructors --------- */
Fixed::Fixed(void)
{
	std::cout << "Constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	value = num * 256;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(num * 256);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* -------- operators --------- */

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->value < other.value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& other) const
{
	if (this->value > other.value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}


Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed	res;
	res.value = (this->value * other.value) / 256;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	Fixed	res;
	res.value = ((float)this->value / (float)other.value) * 256;
	return (res);
}

Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed	res;
	res.value = this->value + other.value;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed	res;
	res.value = this->value - other.value;
	return (res);
}

/* needs to be outside the Fixed class because it's called on an OS object,
by using the friend keyword it can still access the member functions though.
*/
std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

/* -------- functions --------- */

int		Fixed::getRawBits(void) const
{
	std::cout << "Get raw bits function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "set raw bits function called" << std::endl;
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / 256.00);
}

int		Fixed::toInt(void) const
{
	return ((int)value / 256);
}

