/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:32:11 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 17:39:23 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Determines desired index of each value; the smallest value shall have the
** index of 0, while the largest value shall be N. Consequently, the second
** smallest value shall have the index of 1, the second to the largest - N - 1.
*/

static t_node	*next_min(t_cont *cont)
{
	int		i;
	short	has_min;
	t_node	*min;
	t_node	*current;

	min = NULL;
	if (cont->a_start)
	{
		i = 0;
		has_min = FALSE;
		current = cont->a_start;
		while (i < cont->a_size)
		{
			if ((current->index == -1)
				&& (!has_min || current->value < min->value))
			{
				has_min = TRUE;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void			get_index(t_cont *cont)
{
	t_node	*current;
	int		i;

	i = 0;
	while ((current = next_min(cont)))
		current->index = i++;
}
