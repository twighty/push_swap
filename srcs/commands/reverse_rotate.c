/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:50:18 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 18:06:05 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_cont *cont, short rrr)
{
	if (A_FIRST)
	{
		A_FIRST = A_FIRST->prev;
		if (rrr == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;61m") : 0;
			ft_putendl_fd("rra", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont) : 0;
		}
	}
}

void	rrb(t_cont *cont, short rrr)
{
	if (B_FIRST)
	{
		B_FIRST = B_FIRST->prev;
		if (rrr == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;62m") : 0;
			ft_putendl_fd("rrb", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont) : 0;
		}
	}
}

void	rrr(t_cont *cont)
{
	rra(cont, TRUE);
	rrb(cont, TRUE);
	cont->total++;
	cont->opt.c == TRUE ? ft_putstr("\e[38;5;63m") : 0;
	ft_putendl_fd("rrr", cont->fd);
	cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	cont->opt.v == TRUE ? visualiser(cont) : 0;
}
