/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/09 20:20:30 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_etc(t_etc etc, t_stack *s)
{
	etc.tmp = s->top;
	etc.p1 = s->top->val;
	etc.p2 = s->top->next->val;
	etc.n_ra = 0;
	etc.n_rb = 0;
	etc.n_pa = 0;
	etc.n_pb = 0;
}

void	rewind(t_etc etc, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < etc.n_ra && i < etc.n_rb)
		(rrr(a, b, 1) || ++i);
	while (i < etc.n_ra)
		(rra(a, 1) || ++i);
	while (i < etc.n_rb)
		(rrb(b, 1) || ++i);
}

void	atob(t_stack *a, t_stack *b, int count)
{
	int		i;
	t_etc	etc;

	if (count <= 3)
	{
		trivial(a, b, 2)
		return ;
	}
	init_etc(etc, a);
	i = -1;
	while (++i < count)
	{
		if (etc.tmp->val >= etc.p2)
			(ra(a, 1) || ++etc.n_ra);
		else if (etc.tmp->val >= etc.p1)
			(pb(a, b, 1) || ++etc.n_pb || rb(b, 1) || ++etc.n_rb);
		else if (etc.tmp->val < etc.p1)
			(pb(a, b, 1) || ++etc.n_pb);
		etc.tmp = etc.tmp->next;
	}
	rewind(etc, a, b);
	atob(a, b, etc.n_ra);
	btoa(a, b, etc.n_rb);
	btoa(a, b, etc.n_pb - etc.n_rb);
}

void	btoa(t_stack *a, t_stack *b, int count)
{
	int		i;
	t_etc	etc;

	if (count <= 3)
	{
		trivial(a, b, 1)
		return ;
	}
	init_etc(etc, b);
	i = -1;
	while (++i < count)
	{
		if (etc.tmp->val < etc.p1)
			(rb(b, 1) || ++etc.n_rb);
		else if (etc.tmp->val < etc.p2)
			(pa(a, b, 1) || ++etc.n_pa || ra(a, 1) || ++etc.n_ra);
		else if (etc.tmp->val >= etc.p2)
			(pa(a, b, 1) || ++etc.n_pa);
		etc.tmp = etc.tmp->next;
	}
	atob(a, b, etc.n_pa - etc.n_ra);
	rewind(etc, a, b);
	atob(a, b, etc.n_ra);
	btoa(a, b, etc.n_rb);
}
