/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:27:06 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/02 14:51:56 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	get_square_root(const Fixed &val)
{
	Fixed	cur_val(val);

	for (int i = 0; i < 20 && cur_val != Fixed(0.f); ++i)
		cur_val = Fixed(0.5f) * (cur_val + (val / cur_val));

	return (cur_val);
}

static Fixed	get_area(Point const a, Point const b, Point const c)
{
	Fixed	l1_square, l2_square, l3_square, res;

	l1_square = Point::get_length_square(a, b);
	l2_square = Point::get_length_square(a, c);
	l3_square = Point::get_length_square(b, c);
	
	res = Fixed(4) * l1_square * l2_square;
	res = res - ((l1_square + l2_square - l3_square) * (l1_square + l2_square - l3_square));
	res = get_square_root(res);
	res = res / Fixed(4);
	return (res);
}

static bool		is_on_line(Point const a, Point const b, Point const point)
{
	Fixed	l1, l2, l3, dif, thr;

	l1 = Point::get_length_square(a, b);
	l1 = get_square_root(l1);
	l2 = Point::get_length_square(a, point);
	l2 = get_square_root(l2);
	l3 = Point::get_length_square(b, point);
	l3 = get_square_root(l3);

	thr.setRawBits(8);
	dif = (l2 + l3) - l1;
	if (dif < thr)
		return (true);
	else
		return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A1, A2, A3, A, dif, thr;
	
	if (point == a || point == b || point == c) {
		std::cout << "[ the point is on the vertex. ]" << std::endl;
		return (false);
	}
	
	if (is_on_line(a, b, point) == true || \
		is_on_line(a, c, point) == true || \
		is_on_line(b, c, point) == true) {
		std::cout << "[ the point is on the edge. ]" << std::endl;
		return (false);
	}

	A = get_area(a, b, c);
	A1 = get_area(a, b, point);
	A2 = get_area(a, c, point);
	A3 = get_area(b, c, point);

	thr.setRawBits(16);
	dif = (A1 + A2 + A3) - A;
	std::cout << "[ dif : " << dif;
	if (dif < thr) {
		std::cout << " | the point is in the triangle. ]" << std::endl;
		return (true);
	}
	else {
		std::cout << " | the point isn't in the triangle. ]" << std::endl;
		return (false);
	}
}