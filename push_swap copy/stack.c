/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:48:31 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/09 16:32:35 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*new(int val)
{
	t_dlist	*tmp;

	tmp = (t_dlist *)malloc(sizeof(t_dlist));
	tmp->val = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	push(t_stack *s, t_dlist *nod)
{
	if (s->count == 0)
	{
		s->top = nod;
		s->bottom = nod;
		nod->next = s->top;
		nod->prev = s->bottom;
	}
	else
	{
		s->top->prev = nod;
		s->bottom->next = nod;
		nod->next = s->top;
		nod->prev = s->bottom;
		s->top = nod;
	}
	++s->count;
}

t_dlist	*pop(t_stack *s)
{
	t_dlist	*tmp;

	if (s->count == 0)
		return (NULL);
	tmp = s->top;
	if (s->count == 1)
	{
		s->top = NULL;
		s->bottom = NULL;
	}
	else
	{
		s->top = tmp->next;
		s->top->prev = s->bottom;
		s->bottom->next = s->top;
	}
	--s->count;
	return (tmp);
}

void	destroy(t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->count)
		free(pop(s));
	s->count = 0;
}

void	display(t_stack *s)
{
	int		i;
	t_dlist	*tmp;

	ft_printf("----top----\n");
	tmp = s->top;
	i = -1;
	while (++i < s->count)
	{
		ft_printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("---bottom---\n");
}