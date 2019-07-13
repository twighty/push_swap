/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:48:20 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 18:12:16 by akhmetsha        ###   ########.fr       */
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

void	options(t_cont *cont)
{
	if (cont->opt.f == TRUE)
	{
		cont->fd = open("result.log", O_CREAT, O_RDWR);
	}
}

int		main(int argc, char **argv)
{
	t_cont		*container;

	if (argc >= 2)
	{
		container = parser(argc, argv);
		options(container);
		init_sort(container);
		quicksort(container);
		if (container->opt.t == TRUE)
		{
			ft_putstr("Total number of moves: ");
			ft_putstr(ft_itoa(container->total));
			ft_putstr("\n");
		}
		free_container(container);
	}
	else
		terminate(ERR_NO_NUMBERS);
	return (0);
}
