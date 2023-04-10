/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:47:56 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/10 21:56:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	static t_stack	a;
	static t_stack	b;

	receive_input(arc, arv, &a, &b);
	
	atob(&a, &b, a.count);

	// ft_printf("    stack A\n");
	// display(&a);
	// ft_printf("\n\n    stack B\n");
	// display(&b);
	
	success_exit(&a);
}