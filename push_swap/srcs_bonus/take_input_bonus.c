/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:49:46 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/15 18:57:24 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/push_swap_bonus.h"

static int	sub_atoi(char **str, int j, t_stack *b)
{
	size_t		i;
	int			flag;
	long long	res;

	i = 0;
	while ((str[j][i] >= 9 && str[j][i] <= 13) || str[j][i] == 32)
		++i;
	flag = 1;
	if (str[j][i] == '+' || str[j][i] == '-')
		flag *= 44 - str[j][i++];
	if (str[j][i] == '\0')
		error_exit(NULL, b, str, j);
	res = 0;
	while (str[j][i] >= '0' && str[j][i] <= '9')
	{
		res *= 10;
		res += (str[j][i] - '0') * flag;
		++i;
		if (res > 2147483647 || res < -2147483648)
			error_exit(NULL, b, str, j);
	}
	if (i < ft_strlen(str[j]))
		error_exit(NULL, b, str, j);
	return ((int) res);
}

static void	check_dup(t_stack *a)
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
				error_exit(a, NULL, NULL, 0);
			t_nod = t_nod->next;
		}
		c_nod = c_nod->next;
	}
}

static void	check(t_stack *a, t_stack *b)
{
	int		i;
	int		count;

	count = b->count;
	i = -1;
	while (++i < count)
		pa(a, b, 0, NULL);
	check_dup(a);
}

void	take_input(int arc, char **arv, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	char	**strs;
	t_dlist	*tmp;

	if (arc < 2)
		normal_exit(a, b);
	i = 0;
	while (++i < arc)
	{
		strs = ft_split(arv[i], ' ');
		if (strs == NULL)
			memory_exit(a, b, NULL, 0);
		j = -1;
		while (strs[++j] != NULL)
		{
			tmp = new(sub_atoi(strs, j, b));
			if (tmp == NULL)
				memory_exit(a, b, strs, j);
			push(b, tmp);
			free(strs[j]);
		}
		free(strs);
	}
	check(a, b);
}
