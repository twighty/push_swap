/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:48:20 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 19:06:17 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_container(t_cont *container)
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

static void	file_options(t_cont *cont, short done)
{
	if (cont->opt.f == TRUE && done == FALSE)
	{
		cont->fd = open("result.log", O_WRONLY | O_CREAT, 0644);
	}
	if (cont->opt.t == TRUE && done == TRUE)
	{
		ft_putstr_fd("Total number of moves: ", cont->fd);
		ft_putendl_fd(ft_itoa(cont->total), cont->fd);
	}
	if (cont->fd != 1 && done == TRUE)
		close(cont->fd);
	cont->fd == 0 ? cont->fd = 1 : cont->fd;
}

int			main(int argc, char **argv)
{
	t_cont		*container;

	if (argc >= 2)
	{
		container = parser(argc, argv);
		file_options(container, FALSE);
		init_sort(container);
		quicksort(container);
		file_options(container, TRUE);
		free_container(container);
	}
	else
		terminate(ERR_NO_NUMBERS);
	return (0);
}
