/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:28:27 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/04 14:49:42 by mhenin           ###   ########.fr       */
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
		float				toFloat(void) const;
		int					toInt(void) const;
		
		Fixed(void);
		Fixed(const int to_convert);
		Fixed(const float to_convert);
		Fixed(const Fixed &to_copy);
		~Fixed(void);
	};

std::ostream	&operator<<(std::ostream& os, const Fixed &fixed);