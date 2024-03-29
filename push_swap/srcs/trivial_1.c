/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:10:08 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:02:48 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	btoa_three_1(t_stack *a, t_stack *b);
void	btoa_three_2(t_stack *a, t_stack *b);

static void	atob_two(t_stack *a)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	if (tmp1->val > tmp2->val)
		(sa(a, 1));
}

static void	btoa_two(t_stack *a, t_stack *b)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	tmp1 = b->top;
	tmp2 = tmp1->next;
	if (tmp1->val < tmp2->val)
		(sb(b, 1) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
	if (tmp1->val >= tmp2->val)
		(pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
}

static void	atob_three_1(t_stack *a)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val > tmp3->val)
		(ra(a, 1, NULL) || sa(a, 1) || rra(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(sa(a, 1));
	if (tmp1->val < tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(ra(a, 1, NULL) || sa(a, 1) || rra(a, 1) || sa(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val < tmp3->val)
		(sa(a, 1) || ra(a, 1, NULL) || sa(a, 1) || rra(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(sa(a, 1) || ra(a, 1, NULL) || sa(a, 1) || rra(a, 1) || sa(a, 1));
}

static void	atob_three_2(t_stack *a)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val > tmp3->val)
		(rra(a, 1) || sa(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(sa(a, 1));
	if (tmp1->val < tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(rra(a, 1));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val < tmp3->val)
		(ra(a, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(ra(a, 1, NULL) || sa(a, 1));
}

void	trivial(t_stack *a, t_stack *b, int cur_size, int flag)
{
	if (cur_size == 1)
	{
		if (flag == 2)
			pa(a, b, 1, NULL);
	}
	if (cur_size == 2)
	{
		if (flag == 1)
			atob_two(a);
		if (flag == 2)
			btoa_two(a, b);
	}
	if (cur_size == 3)
	{
		if (flag == 1 && a->count != 3)
			atob_three_1(a);
		if (flag == 1 && a->count == 3)
			atob_three_2(a);
		if (flag == 2 && b->count != 3)
			btoa_three_1(a, b);
		if (flag == 2 && b->count == 3)
			btoa_three_2(a, b);
	}
}
