/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:43:42 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 17:58:35 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define FALSE 0
# define TRUE 1

# define ERR_MEMALLOC "Program execution has been terminated (Error: could \
not allocate enough memory)"
# define ERR_NAN "Program execution has been terminated (Error: invalid \
values)"
# define ERR_DUP "Program execution has been terminated (Error: duplicate \
values)"
# define ERR_NO_NUMBERS "Program execution has been terminated (Error: \
insufficient number of values (must be at least two))"
# define ERR_WRONG_OPTION "Program execution has been terminated (Error: \
unknown option(s))"

# define A_FIRST cont->a_start
# define A_FIRST_VALUE cont->a_start->value

# define A_SECOND cont->a_start->next
# define A_SECOND_VALUE cont->a_start->next->value

# define A_PENULT cont->a_end->prev

# define A_LAST cont->a_end
# define A_LAST_VALUE cont->a_end->value

# define B_FIRST cont->b_start
# define B_FIRST_VALUE cont->b_start->value

# define B_SECOND cont->b_start->next
# define B_SECOND_VALUE cont->b_start->next->value

# define B_PENULT cont->b_end->prev

# define B_LAST cont->b_end
# define B_LAST_VALUE cont->b_end->value

typedef struct		s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_opt
{
	short			f;
	short			c;
	short			t;
}					t_opt;

typedef struct 		s_cont
{
	int				index;
	t_opt			opt;
	int				a_size;
	int				b_size;
	int				total;
	int				pivot;
	t_node			*a_start;
	t_node			*b_start;
	t_node			*a_end;
	t_node			*b_end;
	int				fd;
}					t_cont;

/*
** add.c
*/

void		add(t_node **head, t_node **tail, int value);

/*
** init_sort.c
*/

int			is_ordered(t_cont *cont);
void		init_sort_cont(t_cont *cont);
void		init_sort(t_cont *cont);

/*
** parser.c
*/

t_cont	    *parser(int argc, char **argv);

/*
** push.c
*/

void	pa(t_cont *cont);
void	pb(t_cont *cont);

/*
** quicksort.c
*/

void		move_ab(t_cont *cont);
void		quicksort(t_cont *cont);

/*
** reverse_rotate.c
*/

void	rra(t_cont *cont);
void	rrb(t_cont *cont);
void	rrr(t_cont *cont);

/*
** rotate.c
*/

void	ra(t_cont *cont);
void	rb(t_cont *cont);
void	rr(t_cont *cont);

/*
** swap.c
*/

void	sa(t_cont *c);
void	sb(t_cont *c);
void	sx(t_cont *c);

/*
** terminate.c
*/

void		terminate(const char *str);

#endif