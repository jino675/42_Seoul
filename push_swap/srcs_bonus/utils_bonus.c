/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:55:00 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/15 18:02:03 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/push_swap_bonus.h"

void	error_exit(t_stack *a, t_stack *b, char **strs, int j)
{
	if (strs != NULL)
	{
		while (strs[j] != NULL)
		{
			free(strs[j]);
			++j;
		}
		free(strs);
	}
	if (a != NULL)
		destroy(a);
	if (b != NULL)
		destroy(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	memory_exit(t_stack *a, t_stack *b, char **strs, int j)
{	
	if (strs != NULL)
	{
		while (strs[j] != NULL)
		{
			free(strs[j]);
			++j;
		}
		free(strs);
	}
	if (a != NULL)
		destroy(a);
	if (b != NULL)
		destroy(b);
	write(2, "Memory Error\n", 13);
	exit(1);
}

void	normal_exit(t_stack *a, t_stack *b)
{
	if (a != NULL)
		destroy(a);
	if (b != NULL)
		destroy(b);
	exit(0);
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
