/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:54:40 by twight            #+#    #+#             */
/*   Updated: 2019/07/15 22:10:53 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add(t_node **head, t_node **tail, int value)
{
	t_node	*new;
	t_node	*tmp;

	if (!(new = (t_node *)ft_memalloc(sizeof(t_node))))
		terminate(ERR_MEMALLOC);
	new->next = NULL;
	new->value = value;
	new->prev = *tail;
	*tail = new;
	if (*head)
	{
		tmp = *head;
		while (tmp->next && tmp->value != value)
			tmp = tmp->next;
		if (tmp->value == value)
		{
			free(new);
			new = NULL;
			terminate(ERR_DUP);
		}
		tmp->next = new;
	}
	else
		*head = new;
}
