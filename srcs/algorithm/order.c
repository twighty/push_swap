/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:27:41 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 18:38:20 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if Stack A is ordered and contains all the values.
*/

int		is_ordered(t_cont *cont)
{
	t_node	*tmp;
	int		i;

	tmp = A_FIRST;
	i = 0;
	while (i++ < cont->a_size && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (i == cont->a_size && cont->b_size == 0)
		return (1);
	else
		return (0);
}

/*
** Finds out whether the value is ordered, i.e. it is located after the value
** with smaller index.
*/

int		check_index(t_cont *cont, t_node *ind_start)
{
	int		index;
	int		pairs;
	t_node	*current;

	pairs = 0;
	if (cont->a_start && ind_start)
	{
		index = ind_start->index;
		ind_start->keep = TRUE;
		current = ind_start->next;
		while (current != ind_start)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep = TRUE;
			}
			else
				current->keep = FALSE;
			current = current->next;
		}
	}
	return (pairs);
}

void	order_stack(t_cont *cont)
{
	int		i;
	int		current_pairs;
	t_node	*current;

	if (cont->a_start)
	{
		i = 0;
		current = cont->a_start;
		while (i < cont->a_size)
		{
			current_pairs = check_index(cont, current);
			if (current_pairs > cont->pairs)
			{
				cont->index_start = current;
				cont->pairs = current_pairs;
			}
			else if (current_pairs == cont->pairs && \
			(!cont->index_start || current->value < cont->index_start->value))
				cont->index_start = current;
			i++;
			current = current->next;
		}
	}
	check_index(cont, cont->index_start);
}
