/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:51 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/15 18:03:11 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

static void	btoa(t_stack *a, t_stack *b, int count);
void		swap_int(int *a, int *b);
void		rewind(t_etc *etc, t_stack *a, t_stack *b);
void		trivial(t_stack *a, t_stack *b, int count, int flag);

static void	quick_sort(int *arr, int L, int R)
{
	int	l;
	int	r;
	int	pivot;

	if (R - L <= 0)
		return ;
	pivot = arr[L];
	l = L + 1;
	r = R;
	while (l <= r)
	{
		while (l <= R && arr[l] < pivot)
			++l;
		while (arr[r] > pivot)
			--r;
		if (l < r)
		{
			swap_int(&arr[l], &arr[r]);
			++l;
			--r;
		}
	}
	swap_int(&arr[L], &arr[r]);
	quick_sort(arr, L, r - 1);
	quick_sort(arr, l, R);
}

static int	init_pivot(t_etc *e, t_stack *s, int cur_size)
{
	int		*arr;
	int		i;
	t_dlist	*tmp;

	arr = (int *)malloc(sizeof(int) * cur_size);
	if (arr == NULL)
		return (-1);
	tmp = s->top;
	i = -1;
	while (++i < cur_size)
	{
		arr[i] = tmp->val;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, cur_size - 1);
	i = -1;
	while (++i < cur_size)
	{
		if (i == cur_size / 3)
			e->p1 = arr[i];
		else if (i == (cur_size * 2) / 3)
			e->p2 = arr[i];
	}
	free(arr);
	return (0);
}

static int	init_etc(t_etc *e, t_stack *s, int cur_size)
{
	e->tmp = s->top;
	if (init_pivot(e, s, cur_size) == -1)
		return (-1);
	e->n_ra = 0;
	e->n_rb = 0;
	e->n_pa = 0;
	e->n_pb = 0;
	return (0);
}

void	atob(t_stack *a, t_stack *b, int cur_size)
{
	int		i;
	t_etc	e;

	if (cur_size <= 3)
	{
		trivial(a, b, cur_size, 1);
		return ;
	}
	if (init_etc(&e, a, cur_size) == -1)
		memory_exit(a, b, NULL, 0);
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

static void	btoa(t_stack *a, t_stack *b, int cur_size)
{
	int		i;
	t_etc	e;

	if (cur_size <= 3)
	{
		trivial(a, b, cur_size, 2);
		return ;
	}
	if (init_etc(&e, b, cur_size) == -1)
		memory_exit(a, b, NULL, 0);
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
