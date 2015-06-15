/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:58:14 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/12 21:02:51 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed() : val(0), fractionalBits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : val(src.val), fractionalBits(src.fractionalBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const i) : val(i << 8), fractionalBits(8)
{
	std::cout << "Int constructor called" << std::endl;
	val = i << fractionalBits;
}

Fixed::Fixed(float const i) : fractionalBits(8)
{
	std::cout << "Float constructor called" << std::endl;
	val = static_cast<int>(i * (1 << fractionalBits));
	//val = (static_cast<int>(i) << 8) | (static_cast<>() & 0xFF);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->val = rhs.val;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
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

std::ostream &	operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
}
