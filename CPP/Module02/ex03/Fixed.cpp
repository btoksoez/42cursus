/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:30:02 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/16 13:13:10 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* -------- constructors --------- */
Fixed::Fixed(void)
{
	value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	this->value = other.value;
}

Fixed::Fixed(const int num)
{
	value = num * 256;
}

Fixed::Fixed(const float num)
{
	value = roundf(num * 256);
}

Fixed::~Fixed(void) {}

/* -------- comparsion operators --------- */

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.value;
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

/* -------- arithmetic operators --------- */

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

/* -------- stream operator --------- */

/* needs to be outside the Fixed class because it's called on an OS object,
by using the friend keyword it can still access the member functions though.
*/
std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

/* -------- increment/decrement operators --------- */

/* increments value and returns it */
Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

/* returns a copy of the original, so that it can be used for the operation,
but increments the original so next time it's being used it's incremented*/
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	this->value++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->value--;
	return (temp);
}

/* -------- functions --------- */

Fixed&	Fixed::min(Fixed& first, Fixed& other)
{
	if (first.value < other.value)
		return (first);
	else
		return (other);
}

/*
const: When const is used in the context of a function declaration,
it means that the function does not modify the object on which it is called -> can be called on const objects.
static: doesn't need an instance of the class but can just be called and return a reference */
const Fixed&	Fixed::min(const Fixed& first, const Fixed& other)
{
	if (first.getRawBits() < other.getRawBits())
		return (first);
	else
		return (other);
}

Fixed&	Fixed::max(Fixed& first, Fixed& other)
{
	if (first.value > other.value)
		return (first);
	else
		return (other);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& other)
{
	if (first.getRawBits() > other.getRawBits())
		return (first);
	else
		return (other);
}

int		Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
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

