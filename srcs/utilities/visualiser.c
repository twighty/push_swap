/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:20:03 by twight            #+#    #+#             */
/*   Updated: 2019/07/20 00:43:50 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_row(t_node *node)
{
	short	value_len;
	short	i;

	i = 0;
	value_len = ft_strlen(ft_itoa(node->value));
	ft_putchar('|');
	if (value_len % 2 == 0)
	{
		while (i++ <= ((13 - value_len) / 2))
			ft_putchar(' ');
	}
	else
	{
		while (i++ < ((13 - value_len) / 2))
			ft_putchar(' ');
	}
	ft_putstr(ft_itoa(node->value));
	while (i++ <= 13 - value_len)
		ft_putchar(' ');
}

void		visualiser(t_cont *cont, short stack)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	if (stack == FALSE)
		ft_putstr("Move: ");
	else
	{
		tmp_a = cont->a_start;
		tmp_b = cont->b_start;
		ft_putendl("|   Stack A   |   Stack B   |");
		while (tmp_a || tmp_b)
		{
			if (tmp_a)
				print_row(tmp_a);
			else
				ft_putstr("|             ");
			if (tmp_b)
				print_row(tmp_b);
			else
				ft_putstr("|             ");
			ft_putendl("|");
			tmp_a ? tmp_a = tmp_a->next : 0;
			tmp_b ? tmp_b = tmp_b->next : 0;
		}
	}
}
