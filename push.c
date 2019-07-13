/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:38:38 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 18:08:55 by akhmetsha        ###   ########.fr       */
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
		ft_putendl_fd("pa", cont->fd);
		cont->a_size++;
		cont->b_size--;
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
		ft_putendl_fd("pb", cont->fd);
		cont->b_size++;
		cont->a_size--;
	}
}
