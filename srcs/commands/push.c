/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:38:38 by twight            #+#    #+#             */
/*   Updated: 2019/07/20 00:39:40 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_cont *cont)
{
	t_node	*tmp;

	if (B_FIRST)
	{
		tmp = B_FIRST;
		B_FIRST = tmp->next;
		B_FIRST ? B_FIRST->prev = NULL : 0;
		!(B_FIRST) ? B_LAST = NULL : 0;
		A_FIRST ? A_FIRST->prev = tmp : 0;
		tmp->next = A_FIRST;
		A_FIRST = tmp;
		!(A_FIRST->next) ? A_LAST = A_FIRST : 0;
		cont->total++;
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;137m") : 0;
		cont->opt.v == TRUE ? visualiser(cont, FALSE) : 0;
		ft_putendl_fd("pa", cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
		cont->a_size++;
		cont->b_size--;
		cont->opt.v == TRUE ? visualiser(cont, TRUE) : 0;
	}
}

void	pb(t_cont *cont)
{
	t_node	*tmp;

	if (A_FIRST)
	{
		tmp = A_FIRST;
		A_FIRST = tmp->next;
		A_FIRST ? A_FIRST->prev = NULL : 0;
		!(A_FIRST) ? A_LAST = NULL : 0;
		B_FIRST ? B_FIRST->prev = tmp : 0;
		tmp->next = B_FIRST;
		B_FIRST = tmp;
		!(B_FIRST->next) ? B_LAST = B_FIRST : 0;
		cont->total++;
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;138m") : 0;
		cont->opt.v == TRUE ? visualiser(cont, FALSE) : 0;
		ft_putendl_fd("pb", cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
		cont->b_size++;
		cont->a_size--;
		cont->opt.v == TRUE ? visualiser(cont, TRUE) : 0;
	}
}
