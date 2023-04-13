/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:25:49 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:02:50 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	btoa_three_1(t_stack *a, t_stack *b)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp1 = b->top;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(rb(b, 1, NULL) || sb(b, 1) || pa(a, b, 1, NULL) || \
		pa(a, b, 1, NULL) || rrb(b, 1) || pa(a, b, 1, NULL));
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val > tmp3->val)
		(rb(b, 1, NULL) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL) || \
		rrb(b, 1) || pa(a, b, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(rb(b, 1, NULL) || sb(b, 1) || pa(a, b, 1, NULL) || rrb(b, 1) || \
		pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
	if (tmp1->val < tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(sb(b, 1) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL) || \
		pa(a, b, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val < tmp3->val)
		(pa(a, b, 1, NULL) || sb(b, 1) || pa(a, b, 1, NULL) || \
		pa(a, b, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(pa(a, b, 1, NULL) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
}

void	btoa_three_2(t_stack *a, t_stack *b)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp1 = b->top;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(rrb(b, 1) || pa(a, b, 1, NULL) || sb(b, 1) || \
		pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
	if (tmp1->val < tmp2->val && tmp1->val < tmp3->val && tmp2->val > tmp3->val)
		(sb(b, 1) || pa(a, b, 1, NULL) || sb(b, 1) || \
		pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val < tmp3->val && tmp2->val < tmp3->val)
		(rrb(b, 1) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL) || \
		pa(a, b, 1, NULL));
	if (tmp1->val < tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(sb(b, 1) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL) || \
		pa(a, b, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val < tmp3->val)
		(pa(a, b, 1, NULL) || sb(b, 1) || pa(a, b, 1, NULL) || \
		pa(a, b, 1, NULL));
	if (tmp1->val > tmp2->val && tmp1->val > tmp3->val && tmp2->val > tmp3->val)
		(pa(a, b, 1, NULL) || pa(a, b, 1, NULL) || pa(a, b, 1, NULL));
}
