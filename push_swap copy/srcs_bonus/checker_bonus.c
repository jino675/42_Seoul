/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:54:54 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:13:58 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/push_swap_bonus.h"

static void	sub_take_command(char *cmd, t_stack *a, t_stack *b, int *flag)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(a, 0, NULL);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(b, 0, NULL);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(a, b, 0, NULL);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(a, b, 0, NULL);
	else
		*flag = 1;
}

static void	ko_exit(t_stack *a, t_stack *b)
{
	ft_printf("KO\n");
	normal_exit(a, b);
}

static void	ok_exit(t_stack *a, t_stack *b)
{
	ft_printf("OK\n");
	normal_exit(a, b);
}

void	is_ok(t_stack *a, t_stack *b)
{
	int		i;
	int		flag;
	t_dlist	*c_nod;
	t_dlist	*n_nod;

	if (b->count != 0)
		ko_exit(a, b);
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
		ok_exit(a, b);
	else
		ko_exit(a, b);
}

void	take_command(t_stack *a, t_stack *b)
{
	int		flag;
	char	*cmd;

	while (1)
	{
		flag = 0;
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		sub_take_command(cmd, a, b, &flag);
		if (flag == 1)
			error_exit(a, b);
		free(cmd);
	}
}
