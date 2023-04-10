/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:49:46 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/10 20:10:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sub_atoi(char *str)
{
	size_t		i;
	int			flag;
	long long	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	flag = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		flag *= 44 - str[i];
		++i;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - '0') * flag;
		++i;
		if (res > 2147483647 || res < -2147483648)
			error_exit();
	}
	if (i < ft_strlen(str))
		error_exit();
	return ((int) res);
}

void	check_dup(t_stack *a)
{
	int		i;
	int		j;
	t_dlist	*c_nod;
	t_dlist	*t_nod;

	if (a->count < 2)
		return ;
	c_nod = a->top;
	i = -1;
	while (++i < a->count - 1)
	{
		t_nod = c_nod->next;
		j = i;
		while (++j < a->count)
		{
			if (c_nod->val == t_nod->val)
				error_exit();
			t_nod = t_nod->next;
		}
		c_nod = c_nod->next;
	}
}

void	check_aligned(t_stack *a)
{
	int		i;
	int		flag;
	t_dlist	*c_nod;
	t_dlist	*n_nod;

	if (a->count < 2)
		success_exit(a);
	c_nod = a->top;
	flag = 0;
	i = -1;
	while (++i < a->count - 1)
	{
		n_nod = c_nod->next;
		if (n_nod->val - c_nod->val < 0)
			flag = 1;
		c_nod = c_nod->next;
	}
	if (flag == 0)
		success_exit(a);
}

void	receive_input(int arc, char **arv, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		word_count;
	char	**strs;

	if (arc < 2)
		error_exit();
	i = 0;
	while (++i < arc)
	{
		strs = ft_split(arv[i], ' ');
		word_count = 0;
		while (strs[word_count] != NULL)
			++word_count;
		j = -1;
		while (++j < word_count)
			push(b, new(sub_atoi(strs[j])));
	}
	i = -1;
	j = b->count;
	while (++i < j)
		pa(a, b, 0, NULL);
	check_dup(a);
	check_aligned(a);
	
}