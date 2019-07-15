/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:57:11 by twight            #+#    #+#             */
/*   Updated: 2019/07/16 00:44:37 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ordered(t_cont *cont)
{
	t_node *tmp;

	tmp = A_FIRST;
	while (tmp && tmp->next && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp && tmp->next)
		return (0);
	return (1);
}

void	init_sort_cont(t_cont *cont)
{
	if (A_FIRST && A_FIRST_VALUE > A_SECOND_VALUE)
		sa(cont, FALSE);
	if (A_PENULT && A_LAST_VALUE < A_PENULT->value)
	{
		rra(cont, FALSE);
		while (A_PENULT && A_LAST_VALUE < A_PENULT->value)
		{
			pb(cont);
			rb(cont, FALSE);
			rra(cont, FALSE);
		}
		rra(cont, FALSE);
		sa(cont, FALSE);
		while (B_FIRST)
		{
			pa(cont);
			ra(cont, FALSE);
		}
		ra(cont, FALSE);
		ra(cont, FALSE);
	}
}

void	init_sort(t_cont *cont)
{
	while (A_LAST_VALUE < A_FIRST_VALUE)
	{
		if (A_FIRST_VALUE > A_SECOND_VALUE && A_LAST_VALUE != A_SECOND_VALUE)
			sa(cont, FALSE);
		rra(cont, FALSE);
		if (A_FIRST_VALUE > A_SECOND_VALUE && A_LAST_VALUE != A_SECOND_VALUE)
			sa(cont, FALSE);
		while (A_SECOND && A_LAST_VALUE > A_FIRST_VALUE && \
		A_LAST_VALUE < A_SECOND_VALUE)
		{
			move_ab(cont);
			rra(cont, FALSE);
			if (A_FIRST_VALUE > A_SECOND_VALUE && \
			A_LAST_VALUE != A_SECOND_VALUE)
				sa(cont, FALSE);
		}
	}
	while (B_FIRST)
	{
		pa(cont);
		if (A_FIRST_VALUE > A_SECOND_VALUE && A_LAST_VALUE != A_SECOND_VALUE)
			sa(cont, FALSE);
	}
	init_sort_cont(cont);
}
