/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:55 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/10 15:39:01 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_dlist
{
	int				val;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	int				count;
	struct s_dlist	*top;
	struct s_dlist	*bottom;
}	t_stack;

typedef struct s_etc
{
	int		p1;
	int		p2;
	int		n_ra;
	int		n_rb;
	int		n_pa;
	int		n_pb;
	t_dlist	*tmp;
}	t_etc;

t_dlist	*new(int val);
void	push(t_stack *s, t_dlist *nod);
t_dlist	*pop(t_stack *s);
void	destroy(t_stack *s);
void	display(t_stack *s);
int		sa(t_stack *a, int flag);
int		sb(t_stack *b, int flag);
int		ss(t_stack *a, t_stack *b, int flag);
int		rr(t_stack *a, t_stack *b, int flag);
int		rb(t_stack *b, int flag, t_etc *e);
int		ra(t_stack *a, int flag, t_etc *e);
int		rrr(t_stack *a, t_stack *b, int flag);
int		rrb(t_stack *b, int flag);
int		rra(t_stack *a, int flag);
int		pb(t_stack *a, t_stack *b, int flag, t_etc *e);
int		pa(t_stack *a, t_stack *b, int flag, t_etc *e);
void	error_exit(void);
void	success_exit(t_stack *a);
void	receive_input(int arc, char **arv, t_stack *a, t_stack *b);
void	trivial(t_stack *a, t_stack *b, int count, int flag);
void	atob(t_stack *a, t_stack *b, int count);
void	rewind(t_etc *etc, t_stack *a, t_stack *b);

#endif