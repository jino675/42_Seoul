/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:29:23 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:03:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/push_swap_bonus.h"

int	pa(t_stack *a, t_stack *b, int print, t_etc *e)
{
	t_dlist	*tmp;

	if (b->count == 0)
		return (0);
	tmp = pop(b);
	push(a, tmp);
	if (print == 1)
	{
		write(1, "pa\n", 3);
		if (e != NULL)
			++e->n_pa;
	}
	return (0);
}

int	pb(t_stack *a, t_stack *b, int print, t_etc *e)
{
	t_dlist	*tmp;

	if (a->count == 0)
		return (0);
	tmp = pop(a);
	push(b, tmp);
	if (print == 1)
	{
		write(1, "pb\n", 3);
		if (e != NULL)
			++e->n_pb;
	}
	return (0);
}

int	rra(t_stack *a, int print)
{
	t_dlist	*tmp;

	if (a->count < 2)
		return (0);
	tmp = a->bottom;
	a->bottom = tmp->prev;
	a->top = tmp;
	if (print == 1)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack *b, int print)
{
	t_dlist	*tmp;

	if (b->count < 2)
		return (0);
	tmp = b->bottom;
	b->bottom = tmp->prev;
	b->top = tmp;
	if (print == 1)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack *a, t_stack *b, int print)
{
	if (a->count < 2 && b->count < 2)
		return (0);
	rra(a, 0);
	rrb(b, 0);
	if (print == 1)
		write(1, "rrr\n", 4);
	return (0);
}
