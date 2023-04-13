/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:54:46 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/13 17:03:17 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_bonus/push_swap_bonus.h"

int	main(int arc, char **arv)
{
	static t_stack	a;
	static t_stack	b;

	take_input(arc, arv, &a, &b);
	take_command(&a, &b);
	is_ok(&a, &b);
}
