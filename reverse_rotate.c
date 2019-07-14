/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:50:18 by twight            #+#    #+#             */
/*   Updated: 2019/07/14 16:43:54 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_cont *cont)
{
	t_node	*new_start;

	if (A_FIRST && A_SECOND)
	{
		new_start = A_LAST;
		A_LAST = A_PENULT;
		A_LAST->next = NULL;
		new_start->next = A_FIRST;
		new_start->prev = NULL;
		A_FIRST->prev = new_start;
		A_FIRST = new_start;
		cont->total++;
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;61m") : 0;
		ft_putendl_fd("rra", cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	}
}

void	rrb(t_cont *cont)
{
	t_node	*new_start;

	if (B_FIRST && B_SECOND)
	{
		new_start = B_LAST;
		B_LAST = B_PENULT;
		B_LAST->next = NULL;
		new_start->next = B_FIRST;
		new_start->prev = NULL;
		B_FIRST->prev = new_start;
		B_FIRST = new_start;
		cont->total++;
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;62m") : 0;
		ft_putendl_fd("rrb", cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	}
}

void	rrr(t_cont *cont)
{
	t_node	*new_start;

	if (A_FIRST && A_SECOND)
	{
		new_start = A_LAST;
		A_LAST = A_PENULT;
		A_LAST->next = NULL;
		new_start->next = A_FIRST;
		new_start->prev = NULL;
		A_FIRST->prev = new_start;
		A_FIRST = new_start;
	}
	if (B_FIRST && B_SECOND)
	{
		new_start = B_LAST;
		B_LAST = B_PENULT;
		B_LAST->next = NULL;
		new_start->next = B_FIRST;
		new_start->prev = NULL;
		B_FIRST->prev = new_start;
		B_FIRST = new_start;
	}
	cont->total++;
	cont->opt.c == TRUE ? ft_putstr("\e[38;5;63m") : 0;
	ft_putendl_fd("rrr", cont->fd);
	cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
}
