/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:48:58 by twight            #+#    #+#             */
/*   Updated: 2019/07/20 00:45:51 by twight           ###   ########.fr       */
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

static int	parse_line(t_cont *cont, char *line, int possible_error)
{
	if (!(possible_error = ft_strcmp(line, "sa")))
		sa(cont, FALSE);
	else if (!(possible_error = ft_strcmp(line, "sb")))
		sb(cont, FALSE);
	else if (!(possible_error = ft_strcmp(line, "ss")))
		ss(cont);
	else if (!(possible_error = ft_strcmp(line, "pa")))
		pa(cont);
	else if (!(possible_error = ft_strcmp(line, "pb")))
		pb(cont);
	else if (!(possible_error = ft_strcmp(line, "ra")))
		ra(cont, FALSE);
	else if (!(possible_error = ft_strcmp(line, "rb")))
		rb(cont, FALSE);
	else if (!(possible_error = ft_strcmp(line, "rr")))
		rr(cont);
	else if (!(possible_error = ft_strcmp(line, "rra")))
		rra(cont, FALSE);
	else if (!(possible_error = ft_strcmp(line, "rrb")))
		rrb(cont, FALSE);
	else if (!(possible_error = ft_strcmp(line, "rrr")))
		rrr(cont);
	else
		possible_error = -1;
	return (possible_error);
}

static void	parse_moves(t_cont *cont)
{
	char	*line;
	int		result;

	while ((result = get_next_line(cont->fd, &line) > 0))
	{
		if (result == -1)
			terminate(cont->program, ERR_FILEREAD);
		if (!ft_strcmp(line, "Total number of moves:"))
			break ;
		if (parse_line(cont, line, 0) == -1)
			terminate(cont->program, ERR_WRONG_MV);
	}
	if (is_ordered(cont))
	{
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;010m") : 0;
		ft_putendl("OK");
	}
	else
	{
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;009m") : 0;
		ft_putendl("KO");
	}
	cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	cont->opt.f == TRUE ? close(cont->fd) : 0;
}

int			main(int argc, char **argv)
{
	t_cont	*container;

	if (argc >= 2)
	{
		container = parser(argc, argv, CHECK);
		if (container->opt.v == TRUE)
		{
			ft_putstr("\033[0;31m");
			ft_putendl("Initial state:");
			ft_putstr("\033[0m");
			visualiser(container, TRUE);
		}
		parse_moves(container);
		free_container(container);
	}
}
