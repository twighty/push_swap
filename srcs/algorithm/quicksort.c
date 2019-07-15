/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 00:44:59 by twight            #+#    #+#             */
/*   Updated: 2019/07/16 00:10:21 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_rotate(t_cont *cont)
{
	int		i;
	int		value;
	t_node	*tmp;

	i = 0;
	value = A_FIRST_VALUE;
	tmp = B_SECOND;
	if (value > B_FIRST_VALUE && value < B_LAST_VALUE)
		return ;
	while (tmp && (tmp->value > value || tmp->prev->value < value))
	{
		tmp = tmp->next;
		i++;
	}
	if (i < cont->b_size / 2)
		while (B_FIRST_VALUE > value || B_LAST_VALUE < value)
			rb(cont);
	else
		while (B_FIRST_VALUE > value || B_LAST_VALUE < value)
			rrb(cont);
}

static void	optimize_order(t_cont *cont)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = B_FIRST;
	if (tmp)
	{
		while (tmp->next && tmp->value > tmp->next->value && ++i)
		{
			tmp = tmp->next;
			i++;
		}
		if (!tmp)
			return ;
		if (i > cont->b_size / 2)
			while (B_LAST_VALUE > B_FIRST_VALUE)
				rrb(cont);
		else
			while (B_LAST_VALUE > B_FIRST_VALUE)
				rb(cont);
	}
}

void		move_ab(t_cont *cont)
{
	int		value;
	int		done;
	t_node	*tmp;

	done = 0;
	if (A_FIRST && A_SECOND)
		if (A_FIRST_VALUE > A_SECOND_VALUE)
			sa(cont);
	tmp = B_FIRST;
	value = A_FIRST_VALUE;
	while (tmp && value < tmp->value)
		tmp = tmp->next;
	if (!tmp && done == FALSE && ++done)
		optimize_order(cont);
	tmp = B_FIRST;
	while (tmp && value > tmp->value)
		tmp = tmp->next;
	if (!tmp && done == FALSE && ++done)
		optimize_order(cont);
	if (done == FALSE && ++done)
		optimize_rotate(cont);
	pb(cont);
}

/*
** Determines median value to be used as pivot for quicksort.
*/

static int	determine_pivot(t_cont *cont)
{
	int		i;
	int		split;
	t_node	*tmp_1;
	t_node	*tmp_2;

	split = (cont->a_size <= 400) ? 2 : 7;
	tmp_1 = A_FIRST;
	while (tmp_1->next)
	{
		i = 0;
		tmp_2 = A_FIRST;
		while (tmp_2)
		{
			if (tmp_2->value < tmp_1->value)
				i++;
			if (i > (cont->a_size + 1) / split)
				break ;
			tmp_2 = tmp_2->next;
		}
		if (i == (cont->a_size + 1) / split)
			break ;
		tmp_1 = tmp_1->next;
	}
	return (tmp_1->value);
}

/*
** Core quicksort algorithm.
*/

void		quicksort(t_cont *cont)
{
	t_node *tmp;

	while (!is_ordered(cont))
	{
		cont->pivot = determine_pivot(cont);
		while (A_FIRST_VALUE < cont->pivot)
			move_ab(cont);
		while (1)
		{
			tmp = A_FIRST;
			while (tmp && tmp->value >= cont->pivot)
				tmp = tmp->next;
			if (!tmp)
				break ;
			while (A_FIRST_VALUE < cont->pivot)
				move_ab(cont);
			if (A_SECOND && A_FIRST_VALUE > A_SECOND_VALUE && \
			A_SECOND_VALUE > cont->pivot)
				sa(cont);
			(!is_ordered(cont)) ? ra(cont) : 0;
		}
	}
	optimize_order(cont);
	while (B_FIRST)
		pa(cont);
}
