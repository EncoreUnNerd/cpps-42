/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:28:27 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/31 16:48:35 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Fixed
{
	private:
		int					_number;
		static const int	_nbits = 8;
	public:
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		Fixed				&operator=(const Fixed &fixed);
		Fixed				operator*(const Fixed &fixed);
		Fixed				operator+(const Fixed &fixed);
		Fixed				operator-(const Fixed &fixed);
		Fixed				operator/(const Fixed &fixed);
		Fixed				operator++(int);
		Fixed				&operator++();
		Fixed				operator--(int);
		Fixed				&operator--();
		friend std::ostream	&operator<<(std::ostream& os, const Fixed &fixed);
		bool				operator!=(const Fixed &fixed);
		bool				operator==(const Fixed &fixed);
		bool				operator<=(const Fixed &fixed);
		bool				operator>=(const Fixed &fixed);
		bool				operator>(const Fixed &fixed);
		bool				operator<(const Fixed &fixed);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed		min(Fixed &compare1, Fixed &compare2);
		static Fixed		min(const Fixed &compare1, const Fixed &compare2);
		static Fixed		max(Fixed &compare1, Fixed &compare2);
		static Fixed		max(const Fixed &compare1, const Fixed &compare2);
		
		Fixed(void);
		Fixed(const int to_convert);
		Fixed(const float to_convert);
		Fixed(const Fixed &to_copy);
		~Fixed(void);
};