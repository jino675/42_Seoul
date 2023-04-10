/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/10 21:56:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btoa(t_stack *a, t_stack *b, int count);

void	init_etc(t_etc *e, t_stack *s)
{
	int	temp;

	e->tmp = s->top;
	e->p1 = s->top->val;
	e->p2 = s->top->next->val;
	if (e->p1 > e->p2)
	{
		temp = e->p1;
		e->p1 = e->p2;
		e->p2 = temp;
	}
	e->n_ra = 0;
	e->n_rb = 0;
	e->n_pa = 0;
	e->n_pb = 0;
	// ft_printf("p1 : %d, p2 : %d\n", e->p1, e->p2);
}

void	atob(t_stack *a, t_stack *b, int cur_size)
{
	int		i;
	t_etc	e;

	// ft_printf("atob, cur_size : %d, a->count : %d, b->count : %d\n", cur_size, a->count, b->count);
	// ft_printf("    stack A\n");
	// display(a);
	// ft_printf("\n\n    stack B\n");
	// display(b);
	
	if (cur_size <= 3)
	{
		trivial(a, b, cur_size, 1);
		return ;
	}
	init_etc(&e, a);
	i = -1;
	while (++i < cur_size)
	{
		if (e.tmp->val >= e.p2)
			(ra(a, 1, &e));
		else if (e.tmp->val > e.p1)
			(pb(a, b, 1, &e) || rb(b, 1, &e));
		else if (e.tmp->val <= e.p1)
			(pb(a, b, 1, &e));
		e.tmp = a->top;
	}
	rewind(&e, a, b);
	atob(a, b, e.n_ra);
	btoa(a, b, e.n_rb);
	btoa(a, b, e.n_pb - e.n_rb);
}

void	btoa(t_stack *a, t_stack *b, int cur_size)
{
	int		i;
	t_etc	e;
	
	// ft_printf("btoa, cur_size : %d, a->count : %d, b->count : %d\n", cur_size, a->count, b->count);
	// ft_printf("    stack A\n");
	// display(a);
	// ft_printf("\n\n    stack B\n");
	// display(b);
	
	if (cur_size <= 3)
	{
		trivial(a, b, cur_size, 2);
		return ;
	}
	init_etc(&e, b);
	i = -1;
	while (++i < cur_size)
	{
		if (e.tmp->val <= e.p1)
			(rb(b, 1, &e));
		else if (e.tmp->val < e.p2)
			(pa(a, b, 1, &e) || ra(a, 1, &e));
		else if (e.tmp->val >= e.p2)
			(pa(a, b, 1, &e));
		e.tmp = b->top;
	}
	atob(a, b, e.n_pa - e.n_ra);
	rewind(&e, a, b);
	atob(a, b, e.n_ra);
	btoa(a, b, e.n_rb);
}