/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:20:30 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:02:41 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

typedef struct s_part
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	max_a_c;
	int	max_b_d;
	int	idx_1;
	int	idx_2;
}	t_part;

static void	sub_init(t_part *p, t_etc *e, t_stack *a, t_stack *b)
{
	p->a = a->count - e->n_ra;
	p->b = e->n_ra;
	p->c = b->count - e->n_rb;
	p->d = e->n_rb;
	if (p->a - p->c > 0)
		p->max_a_c = p->a;
	else
		p->max_a_c = p->c;
	if (p->b - p->d > 0)
		p->max_b_d = p->b;
	else
		p->max_b_d = p->d;
	p->idx_1 = 0;
	p->idx_2 = 0;
}

static void	together(t_part *p, t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
	{
		while (p->idx_1 < p->a && p->idx_1 < p->c)
			(rr(a, b, 1) || ++p->idx_1);
		while (p->idx_2 < p->a - p->idx_1)
			(ra(a, 1, NULL) || ++p->idx_2);
		while (p->idx_2 < p->c - p->idx_1)
			(rb(b, 1, NULL) || ++p->idx_2);
	}
	if (flag == 2)
	{
		while (p->idx_1 < p->b && p->idx_1 < p->d)
			(rrr(a, b, 1) || ++p->idx_1);
		while (p->idx_2 < p->b - p->idx_1)
			(rra(a, 1) || ++p->idx_2);
		while (p->idx_2 < p->d - p->idx_1)
			(rrb(b, 1) || ++p->idx_2);
	}
}

static void	sub_rewind_1(t_part *p, t_stack *a, t_stack *b)
{
	if (p->max_a_c <= p->max_b_d && p->max_a_c <= p->b + p->c)
		together(p, a, b, 1);
	else if (p->max_b_d <= p->b + p->c && p->max_b_d <= p->max_a_c)
		together(p, a, b, 2);
	else if (p->b + p->c <= p->max_b_d && p->b + p->c <= p->max_a_c)
	{
		while (p->idx_1 < p->b)
			(rra(a, 1) || ++p->idx_1);
		while (p->idx_2 < p->c)
			(rb(b, 1, NULL) || ++p->idx_2);
	}
}

static void	sub_rewind_2(t_part *p, t_stack *a, t_stack *b)
{
	if (p->max_a_c <= p->max_b_d && p->max_a_c <= p->a + p->d)
		together(p, a, b, 1);
	else if (p->max_b_d <= p->a + p->d && p->max_b_d <= p->max_a_c)
		together(p, a, b, 2);
	else if (p->a + p->d <= p->max_b_d && p->a + p->d <= p->max_a_c)
	{
		while (p->idx_1 < p->a)
			(ra(a, 1, NULL) || ++p->idx_1);
		while (p->idx_2 < p->d)
			(rrb(b, 1) || ++p->idx_2);
	}
}

void	rewind(t_etc *e, t_stack *a, t_stack *b)
{
	t_part	p;

	sub_init(&p, e, a, b);
	if (p.b > p.a && p.d > p.c)
		together(&p, a, b, 1);
	else if (p.b <= p.a && p.d <= p.c)
		together(&p, a, b, 2);
	else if (p.b <= p.a && p.d > p.c)
		sub_rewind_1(&p, a, b);
	else if (p.b > p.a && p.d <= p.c)
		sub_rewind_2(&p, a, b);
}
