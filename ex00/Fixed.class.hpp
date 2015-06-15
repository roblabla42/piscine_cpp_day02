/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:49:32 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/12 16:58:30 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{

	int			val;
	const int	fractionalBits;
public:
	Fixed();
	Fixed(Fixed const & src);
	~Fixed();

	Fixed		&operator=(Fixed const &rhs);

	int			getRawBits() const;
	void		setRawBits(int const raw);
};

#endif
