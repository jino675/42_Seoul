/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:52:50 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/09 17:43:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *a, int flag)
{
	t_dlist	*tmp;

	if (a->count < 2)
		return (0);
	tmp = pop(a);
	tmp->next = a->top->next;
	a->top->next->prev = tmp;
	a->top->next = tmp;
	tmp->prev = a->top;
	++a->count;
	if (flag == 1)
		write(1, "sa\n", 3);
	return (0);
}

void	sb(t_stack *b, int flag)
{
	t_dlist	*tmp;

	if (b->count < 2)
		return (0);
	tmp = pop(b);
	tmp->next = b->top->next;
	b->top->next->prev = tmp;
	b->top->next = tmp;
	tmp->prev = b->top;
	++b->count;
	if (flag == 1)
		write(1, "sb\n", 3);
	return (0);
}

void	ss(t_stack *a, t_stack *b, int flag)
{
	if (a->count < 2 && b->count < 2)
		return (0);
	sa(a, 0);
	sb(b, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
	return (0);
}
