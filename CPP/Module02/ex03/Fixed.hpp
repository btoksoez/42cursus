/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:22:08 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/20 12:24:27 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed&				operator=(const Fixed& other);
		bool				operator<(const Fixed& other) const;
		bool				operator>(const Fixed& other) const;
		bool				operator<=(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool				operator==(const Fixed& other) const;
		bool				operator!=(const Fixed& other) const;

		Fixed				operator*(const Fixed& other);
		Fixed				operator/(const Fixed& other);
		Fixed				operator+(const Fixed& other);
		Fixed				operator-(const Fixed& other);

		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed&		min(Fixed& first, Fixed& other);
		static const Fixed&	min(const Fixed& first, const Fixed& other);
		static Fixed&		max(Fixed& first, Fixed& other);
		static const Fixed&	max(const Fixed& first, const Fixed& other);

		friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

};

Fixed	abs(const Fixed& num);

#endif // FIXED_HPP
