/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:47:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 21:02:13 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	main(int arc, char **arv)
{
	static t_stack	a;
	static t_stack	b;

	take_input(arc, arv, &a, &b);
	atob(&a, &b, a.count);
	normal_exit(&a, &b);
}
