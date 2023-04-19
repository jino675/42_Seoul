/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:55 by jiryu             #+#    #+#             */
/*   Updated: 2023/04/15 18:07:59 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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
int		sa(t_stack *a, int print);
int		sb(t_stack *b, int print);
int		ss(t_stack *a, t_stack *b, int print);
int		rr(t_stack *a, t_stack *b, int print);
int		rb(t_stack *b, int print, t_etc *e);
int		ra(t_stack *a, int print, t_etc *e);
int		rrr(t_stack *a, t_stack *b, int print);
int		rrb(t_stack *b, int print);
int		rra(t_stack *a, int print);
int		pb(t_stack *a, t_stack *b, int print, t_etc *e);
int		pa(t_stack *a, t_stack *b, int print, t_etc *e);
void	error_exit(t_stack *a, t_stack *b, char **strs, int j);
void	normal_exit(t_stack *a, t_stack *b);
void	memory_exit(t_stack *a, t_stack *b, char **strs, int j);
void	take_input(int arc, char **arv, t_stack *a, t_stack *b);
void	atob(t_stack *a, t_stack *b, int count);
// void	display(t_stack *s);

#endif