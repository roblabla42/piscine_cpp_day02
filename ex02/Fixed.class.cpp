/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:58:14 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/18 20:57:30 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : val(0)
{
}

Fixed::Fixed(Fixed const & src) : val(src.val)
{
}

Fixed::Fixed(int const i)
{
	val = i << fractionalBits;
}

Fixed::Fixed(float const i)
{
	val = (int)(roundf(i * (1 << fractionalBits)));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->val = rhs.val;
	return (*this);
}

int		Fixed::getRawBits() const
{
	return val;
}

void	Fixed::setRawBits(int const raw)
{
	val = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(val) / (1 << fractionalBits);
}
int		Fixed::toInt() const
{
	return val >> fractionalBits;
}

bool	Fixed::operator>(Fixed const& rhs) const
{
	return (this->val > rhs.val);
}

bool	Fixed::operator<(Fixed const& rhs) const
{
	return (this->val < rhs.val);
}

bool	Fixed::operator>=(Fixed const& rhs) const
{
	return (this->val >= rhs.val);
}


bool	Fixed::operator<=(Fixed const& rhs) const
{
	return (this->val <= rhs.val);
}

bool	Fixed::operator==(Fixed const& rhs) const
{
	return (this->val == rhs.val);
}

bool	Fixed::operator!=(Fixed const& rhs) const
{
	return (this->val != rhs.val);
}

Fixed	Fixed::operator+(Fixed rhs)
{
	Fixed	f;

	f.setRawBits(this->val + rhs.val);
	return (f);
}

Fixed	Fixed::operator-(Fixed rhs)
{
	Fixed	f;

	f.setRawBits(this->val - rhs.val);
	return (f);
}

Fixed	Fixed::operator*(Fixed rhs)
{
	Fixed	f;
	int		result;

	result = val * rhs.val;
	result += 1 << (fractionalBits - 1);
	result >>= fractionalBits;

	f.setRawBits(result);
	return (f);
}

Fixed	Fixed::operator/(Fixed rhs)
{
	Fixed	f;
	int		result;

	result = val << fractionalBits;
	result += rhs.val / 2;
	result /= rhs.val;

	f.setRawBits(result);
	return (f);
}

Fixed	&Fixed::operator++()
{
	++this->val;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);
	++(*this);
	return (result);
}

Fixed	&Fixed::operator--()
{
	--this->val;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);
	--(*this);
	return (result);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	const&Fixed::min(Fixed const&lhs, Fixed const&rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed	const&Fixed::max(Fixed const&lhs, Fixed const&rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

std::ostream &	operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

const int Fixed::fractionalBits = 8;
