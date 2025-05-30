/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:28:27 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/31 14:53:08 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Fixed
{
	private:
		int					_number;
		static const int	_nbits = 8;
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed	&operator=(const Fixed &fixed);
		
		Fixed(void);
		Fixed(const Fixed &to_copy);
		~Fixed(void);
};