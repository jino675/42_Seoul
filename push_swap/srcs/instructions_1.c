/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:52:50 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:02:30 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	sa(t_stack *a, int print)
{
	t_dlist	*tmp;

	if (a->count < 2)
		return (0);
	tmp = pop(a);
	ra(a, 0, NULL);
	push(a, tmp);
	rra(a, 0);
	if (print == 1)
		write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack *b, int print)
{
	t_dlist	*tmp;

	if (b->count < 2)
		return (0);
	tmp = pop(b);
	rb(b, 0, NULL);
	push(b, tmp);
	rrb(b, 0);
	if (print == 1)
		write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack *a, t_stack *b, int print)
{
	if (a->count < 2 && b->count < 2)
		return (0);
	sa(a, 0);
	sb(b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
	return (0);
}
