/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:44:52 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 18:08:08 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_cont *cont)
{
	t_node	*new_end;

	if (A_FIRST && (A_FIRST)->next)
	{
		new_end = A_FIRST;
		A_FIRST = A_SECOND;
		A_FIRST->prev = NULL;
		new_end->prev = A_LAST;
		new_end->next = NULL;
		A_LAST->next = new_end;
		A_LAST = new_end;
		cont->total++;
		ft_putendl_fd("ra", cont->fd);
	}
}

void	rb(t_cont *cont)
{
	t_node	*new_end;

	if (B_FIRST && B_SECOND)
	{
		new_end = B_FIRST;
		B_FIRST = B_SECOND;
		B_FIRST->prev = NULL;
		new_end->prev = B_LAST;
		new_end->next = NULL;
		B_LAST->next = new_end;
		B_LAST = new_end;
		cont->total++;
		ft_putendl_fd("rb", cont->fd);
	}
}

void	rr(t_cont *cont)
{
	t_node	*new_end;

	if (A_FIRST && A_SECOND)
	{
		new_end = A_FIRST;
		A_FIRST = A_SECOND;
		A_FIRST->prev = NULL;
		new_end->prev = A_LAST;
		new_end->next = NULL;
		A_LAST->next = new_end;
		A_LAST = new_end;
	}
	if (B_FIRST && B_SECOND)
	{
		new_end = B_FIRST;
		B_FIRST = B_SECOND;
		B_FIRST->prev = NULL;
		new_end->prev = B_LAST;
		new_end->next = NULL;
		B_LAST->next = new_end;
		B_LAST = new_end;
	}
	cont->total++;
	ft_putendl_fd("rr", cont->fd);
}
