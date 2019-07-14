/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:28:55 by twight            #+#    #+#             */
/*   Updated: 2019/07/14 21:16:35 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_cont *c)
{
	t_node *tmp;

	if (c->a_start && c->a_start->next)
	{
		tmp = c->a_start->next;
		c->a_start->next->next ? c->a_start->next->next->prev = c->a_start : 0;
		!(c->a_start->next->next) ? c->a_end = c->a_start : 0;
		c->a_start->next = c->a_start->next->next;
		c->a_start->prev = tmp;
		tmp->prev = NULL;
		tmp->next = c->a_start;
		c->a_start = tmp;
		c->total++;
		c->opt.c == TRUE ? ft_putstr("\e[38;5;214m") : 0;
		ft_putendl_fd("sa", c->fd);
		c->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	}
}

void	sb(t_cont *c)
{
	t_node *tmp;

	if (c->b_start && c->b_start->next)
	{
		tmp = c->b_start->next;
		c->b_start->next->next ? c->b_start->next->next->prev = c->b_start : 0;
		!(c->b_start->next->next) ? c->b_end = c->b_start : 0;
		c->b_start->next = c->b_start->next->next;
		c->b_start->prev = tmp;
		tmp->prev = NULL;
		tmp->next = c->b_start;
		c->b_start = tmp;
		c->total++;
		c->opt.c == TRUE ? ft_putstr("\e[38;5;215m") : 0;
		ft_putendl_fd("sb", c->fd);
		c->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	}
}

void	ss(t_cont *c)
{
	t_node *tmp;

	if (c->a_start && c->a_start->next)
	{
		tmp = c->a_start->next;
		c->a_start->next->next ? c->a_start->next->next->prev = c->a_start : 0;
		!(c->a_start->next->next) ? c->a_end = c->a_start : 0;
		c->a_start->next = c->a_start->next->next;
		c->a_start->prev = tmp;
		tmp->prev = NULL;
		tmp->next = c->a_start;
		c->a_start = tmp;
	}
	if (c->b_start && c->b_start->next && (tmp = c->b_start->next))
	{
		c->b_start->next->next ? c->b_start->next->next->prev = c->b_start : 0;
		!(c->b_start->next->next) ? c->b_end = c->b_start : 0;
		c->b_start->next = c->b_start->next->next;
		c->b_start->prev = tmp;
		tmp->prev = NULL;
		tmp->next = c->b_start;
		c->b_start = tmp;
	}
	c->opt.c == TRUE ? ft_putstr("\e[38;5;216m") : 0;
	ft_putendl_fd("ss", c->fd);
	c->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
}
