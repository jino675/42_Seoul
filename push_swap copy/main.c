/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:47:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/09 20:23:18 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	static t_stack	a;
	static t_stack	b;

	receive_input(arc, arv, &a, &b);
	atob(&a, &b, a.count);
	display(&a);
	success_exit(&a);
}