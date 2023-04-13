/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:04:16 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:02:32 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	ra(t_stack *a, int print, t_etc *e)
{
	t_dlist	*tmp;

	if (a->count > 1)
	{
		tmp = a->top;
		a->top = tmp->next;
		a->bottom = tmp;
		if (print == 1)
			write(1, "ra\n", 3);
	}
	if (a->count > 0 && e != NULL)
		++e->n_ra;
	return (0);
}

int	rb(t_stack *b, int print, t_etc *e)
{
	t_dlist	*tmp;

	if (b->count > 1)
	{
		tmp = b->top;
		b->top = tmp->next;
		b->bottom = tmp;
		if (print == 1)
			write(1, "rb\n", 3);
	}
	if (b->count > 0 && e != NULL)
		++e->n_rb;
	return (0);
}

int	rr(t_stack *a, t_stack *b, int print)
{	
	if (a->count < 2 && b->count < 2)
		return (0);
	ra(a, 0, NULL);
	rb(b, 0, NULL);
	if (print == 1)
		write(1, "rr\n", 3);
	return (0);
}
