/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:20:34 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/01 22:02:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : integer(0)
{
}

Fixed::Fixed(const int val)
{
	integer = val << FWL;
}

Fixed::Fixed(const float val)
{
	int				exp, frac_part;
	float			temp;
	unsigned int	raw_val;
	
	if (val < 0 && val - (int)val != 0) {
		integer = ((int)val - 1) << FWL;
		temp = val - ((int)val - 1);
	}
	else {
		integer = (int)val << FWL;
		temp = val - (int)val;
	}
	raw_val = *(unsigned int *)&temp;
	exp = (int)((raw_val & 0x7F800000) >> 23) - 127;
	raw_val = (int)((raw_val & 0x007FFFFF) | 0x00800000);
	if (exp < 0)
		raw_val = raw_val >> (-1 * exp);
	else
		raw_val = raw_val << exp;
	frac_part = (raw_val & 0x007FFFFF) >> (23 - FWL);
	if ((raw_val & 0x00004000) == 0x00004000)
		++frac_part;	
	integer = integer + frac_part;
}
	
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed(void)
{
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	integer = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (integer);
}

void	Fixed::setRawBits(int const raw)
{
	integer = raw;
}

float	Fixed::toFloat(void) const
{
	int				exp, temp;
	float			res;
	unsigned int	raw_val;

	temp = integer >> FWL;
	res = (float)temp;

	raw_val = integer & 0x000000FF;
	if (raw_val != 0) {
		for (exp = 0; (raw_val & 0x00000100) != 0x00000100; --exp)
			raw_val <<= 1;
		exp += 127;
		raw_val = (raw_val & 0x000000FF) << (23 - FWL);
		raw_val |= exp << (31 - 8);
		res += *(float *)&raw_val;	
	}
	return (res);
}

int	Fixed::toInt(void) const
{
	if (integer < 0 && (integer & 0x000000FF) != 0)
		return ((integer >> FWL) + 1);
	else
		return (integer >> FWL);	
}

std::ostream	&operator<<(std::ostream &os, const Fixed &cur)
{
	os << cur.toFloat(); 
	return (os);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (integer > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (integer >= other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (integer < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (integer <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (integer == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (integer != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	temp;

	temp.setRawBits(integer + other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	temp;

	temp.setRawBits(integer - other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	temp;

	temp.setRawBits((int)(((long long)integer * (long long)other.getRawBits()) >> FWL));
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	temp;

	temp.setRawBits((int)(((long long)integer << FWL) / (long long)other.getRawBits()));
	return (temp);
}

Fixed	&Fixed::operator++(void)
{
	++integer;

	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++integer;

	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	--integer;

	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--integer;

	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}