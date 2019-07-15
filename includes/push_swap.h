/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:43:42 by twight            #+#    #+#             */
/*   Updated: 2019/07/16 00:42:48 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define FALSE 0
# define TRUE 1

# define PUSH 0
# define CHECK 1

# define ERR_FILENAME "Program terminated, error: could not find the file"
# define ERR_FILEREAD "Program terminated, error: could not read the file"
# define ERR_MEMALLOC "Program terminated, error: could not allocate memory"
# define ERR_NAN "Program terminated, error: invalid values"
# define ERR_DUP "Program terminated, error: duplicate values"
# define ERR_NO_NUMBERS "Program terminated, error: not enough values"
# define ERR_WRONG_MV "Program terminated, error: unknown or invalid command"
# define ERR_WR_FLAG "Program terminated, error: unknown or invalid option(s))"

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

typedef struct		s_cont
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
	short			program;
}					t_cont;

/*
** add.c
*/

void				add(t_node **head, t_node **tail, int value);

/*
** init_sort.c
*/

int					is_ordered(t_cont *cont);
void				init_sort_cont(t_cont *cont);
void				init_sort(t_cont *cont);

/*
** parser.c
*/

t_cont				*parser(int argc, char **argv, short program);

/*
** push.c
*/

void				pa(t_cont *cont);
void				pb(t_cont *cont);

/*
** quicksort.c
*/

void				move_ab(t_cont *cont);
void				quicksort(t_cont *cont);

/*
** reverse_rotate.c
*/

void				rra(t_cont *cont, short rrr);
void				rrb(t_cont *cont, short rrr);
void				rrr(t_cont *cont);

/*
** rotate.c
*/

void				ra(t_cont *cont, short rr);
void				rb(t_cont *cont, short rr);
void				rr(t_cont *cont);

/*
** swap.c
*/

void				sa(t_cont *c, short ss);
void				sb(t_cont *c, short ss);
void				ss(t_cont *c);

/*
** terminate.c
*/

void				terminate(const char *str);

/*
** experimental.c
*/

void				experimental(t_cont *cont);

#endif
