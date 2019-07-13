/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:48:20 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 16:36:36 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_container(t_cont *container)
{
	t_node	*tmp;
	
	if (container->a_start)
	{
		while (container->a_start)
		{
			tmp = container->a_start->next;
			free(container->a_start);
			container->a_start = tmp;
		}
	}
	free(container);
}

int		main(int argc, char **argv)
{
	t_cont		*container;

	if (argc >= 2)
	{
		container = parser(argc, argv);
		init_sort(container);
		quicksort(container);
		free_container(container);
	}
	return (0);
}
