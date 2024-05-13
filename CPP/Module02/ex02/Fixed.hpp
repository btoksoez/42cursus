/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:22:08 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/12 07:56:37 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
};

#endif // FIXED_HPP