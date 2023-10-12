/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:03:38 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/01 22:33:47 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) :
x(0), y(0)
{
}

Point::Point(const float x, const float y) :
x(x), y(y)
{
}

Point::Point(const Point &other) :
x(other.x), y(other.y)
{
}

Point::~Point(void)
{
}

Point	&Point::operator=(const Point &other)
{
	const_cast<Fixed &>(x) = other.x;
	const_cast<Fixed &>(y) = other.y;
	
	return (*this);
}

bool	Point::operator==(const Point &other) const
{
	return (x == other.x && y == other.y);
}

Fixed	Point::get_length_square(const Point &a, const Point &b)
{
	Fixed	res;

	res = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return (res);
}

Fixed	Point::get_x(void)
{
	return (x);
}

Fixed	Point::get_y(void)
{
	return (y);
}