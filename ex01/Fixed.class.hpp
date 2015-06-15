/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:49:32 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/12 17:14:21 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{

	int			val;
	const int	fractionalBits;
public:
	Fixed();
	Fixed(Fixed const & src);

	Fixed(int const i);
	Fixed(float const i);

	~Fixed();

	Fixed		&operator=(Fixed const &rhs);

	int			getRawBits() const;
	void		setRawBits(int const raw);

	float		toFloat() const;
	int			toInt() const;
};

std::ostream &	operator<<(std::ostream &o, Fixed const &i);

#endif
