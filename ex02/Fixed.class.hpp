/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:49:32 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/13 15:05:58 by roblabla         ###   ########.fr       */
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

	bool			operator>(Fixed const& lhs) const;
	bool			operator<(Fixed const& lhs) const;
	bool			operator>=(Fixed const& lhs) const;
	bool			operator<=(Fixed const& lhs) const;
	bool			operator==(Fixed const& lhs) const;
	bool			operator!=(Fixed const& lhs) const;
	
	Fixed			operator+(Fixed lhs);
	Fixed			operator-(Fixed lhs);
	Fixed			operator*(Fixed lhs);
	Fixed			operator/(Fixed lhs);

	Fixed			&operator++();
	Fixed			operator++(int);
	Fixed			&operator--();
	Fixed			operator--(int);

	static Fixed	&min(Fixed &lhs, Fixed &rhs);
	static Fixed	const&min(Fixed const& lhs, Fixed const& rhs);
	static Fixed	&max(Fixed &lhs, Fixed &rhs);
	static Fixed	const&max(Fixed const& lhs, Fixed const& rhs);
};

std::ostream &	operator<<(std::ostream &o, Fixed const &i);



#endif
