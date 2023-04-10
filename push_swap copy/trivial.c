/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:10:08 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/09 20:12:24 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob_two(t_stack *a, t_stack *b, int count)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	if (tmp1->val > tmp2->val)
		(sa(a, 1));
}

void	btoa_two(t_stack *a, t_stack *b, int count)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	tmp1 = b->top;
	tmp2 = tmp1->next;
	if (tmp1->val < tmp2->val)
		(sb(b, 1) || pa(a, b, 1) || pa(a, b, 1));
	else
		(pa(a, b, 1) || pa(a, b, 1));
}

void	atob_three(t_stack *a, t_stack *b, int count)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val > tmp3->val)
		(ra(a, 1) || sa(a, 1) || rra(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(sa(a, 1));
	if (tmp1->val < tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(ra(a, 1) || sa(a, 1) || rra(a, 1) || sa(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val < tmp3->val)
		(sa(a, 1) || ra(a, 1) || sa(a, 1) || rra(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(sa(a, 1) || ra(a, 1) || sa(a, 1) || rra(a, 1) || sa(a, 1));
}

void	btoa_three(t_stack *a, t_stack *b, int count)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(rb(b, 1) || sb(b, 1) || pa(a, b, 1) || pa(a, b, 1) || \
		rrb(b, 1) || pa(a ,b, 1));
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val > tmp3->val)
		(rb(b, 1) || pa(a, b, 1) || pa(a, b, 1) || rrb(b, 1) || pa(a, b, 1));
	if (tmp1->val > tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(rb(b, 1) || sb(b, 1) || pa(a, b, 1) || rrb(b, 1) || pa(a, b, 1) || \
		pa(a, b, 1));
	if (tmp1->val < tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(sb(b, 1) || pa(a, b, 1) || pa(a, b, 1) || pa(a, b, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val < tmp3->val)
		(pa(a, b, 1) || sb(b, 1) || pa(a, b, 1) || pa(a, b, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(pa(a, b, 1) || pa(a, b, 1) || pa(a, b, 1));
}

void	trivial(t_stack *a, t_stack *b, int count, int flag)
{
	if (count == 1)
	{
		if (flag == 2)
			pa(a, b, 1);
	}
	if (count == 2)
	{
		if (flag == 1)
			atob_two(a, b, count);
		if (flag == 2)
			btoa_two(a, b, count);
	}
	if (count == 3)
	{
		if (flag == 1)
			atob_three(a, b, count);
		if (flag == 2)
			btoa_three(a, b, count);
	}
}