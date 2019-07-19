/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:28:55 by twight            #+#    #+#             */
/*   Updated: 2019/07/19 23:42:23 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_cont *cont, short ss)
{
	t_node *tmp;

	if (A_FIRST && A_SECOND)
	{
		tmp = A_SECOND;
		A_SECOND->next ? A_SECOND->next->prev = A_FIRST : 0;
		!A_SECOND->next ? A_LAST = A_FIRST : 0;
		A_SECOND = A_SECOND->next;
		A_FIRST->prev = tmp;
		tmp->prev = NULL;
		tmp->next = A_FIRST;
		A_FIRST = tmp;
		if (ss == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;214m") : 0;
			cont->opt.v == TRUE ? visualiser(cont, FALSE) : 0;
			ft_putendl_fd("sa", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont, TRUE) : 0;
		}
	}
}

void	sb(t_cont *cont, short ss)
{
	t_node *tmp;

	if (B_FIRST && B_SECOND)
	{
		tmp = B_SECOND;
		B_SECOND->next ? B_SECOND->next->prev = B_FIRST : 0;
		!B_SECOND->next ? B_LAST = B_FIRST : 0;
		B_SECOND = B_SECOND->next;
		B_FIRST->prev = tmp;
		tmp->prev = NULL;
		tmp->next = B_FIRST;
		B_FIRST = tmp;
		if (ss == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;215m") : 0;
			cont->opt.v == TRUE ? visualiser(cont, FALSE) : 0;
			ft_putendl_fd("sb", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont, TRUE) : 0;
		}
	}
}

void	ss(t_cont *cont)
{
	sa(cont, TRUE);
	sb(cont, TRUE);
	cont->total++;
	cont->opt.c == TRUE ? ft_putstr("\e[38;5;216m") : 0;
	cont->opt.v == TRUE ? visualiser(cont, FALSE) : 0;
	ft_putendl_fd("ss", cont->fd);
	cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	cont->opt.v == TRUE ? visualiser(cont, TRUE) : 0;
}
