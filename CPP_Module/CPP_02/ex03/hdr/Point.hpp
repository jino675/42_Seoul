/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:51:28 by jiryu             #+#    #+#             */
/*   Updated: 2023/10/01 22:33:45 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
	Fixed const	x;
	Fixed const	y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &other);
	~Point(void);
	Point	&operator=(const Point &other);
	
	bool	operator==(const Point &other) const;
	Fixed	get_x(void);
	Fixed	get_y(void);
	static	Fixed get_length_square(const Point &a, const Point &b);
};

#endif