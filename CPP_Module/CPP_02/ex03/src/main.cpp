/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:43:59 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/01 22:45:28 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	bool	res;
	Point	a;
	Point	b(5.f, 5.f);
	Point	c(10.f, 2.5f);
	Point	point;
	
	std::cout << "a : (" << a.get_x() << ", " << a.get_y() << ")";
	std::cout << ", b : (" << b.get_x() << ", " << b.get_y() << ")";
	std::cout << ", c : (" << c.get_x() << ", " << c.get_y() << ")\n\n";

	point = Point(0.5f, 0.5f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";

	point = Point(2.5f, 2.5f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";

	point = Point(5.f, 2.5f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";
					
	point = Point(5.f, 5.f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";
					
	point = Point(5.1f, 5.f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";
					
	point = Point(4.f, 2.825f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";
					
	point = Point(7.f, 0.825f);
	res = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << "), res : " << res << "\n\n";	
		
	return (0);
}