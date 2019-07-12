/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:50:18 by twight            #+#    #+#             */
/*   Updated: 2019/07/12 03:12:07 by twight           ###   ########.fr       */
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
		ft_putstr("rra\n");
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
		ft_putstr("rrb\n");
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
	ft_putstr("rrr\n");
}
