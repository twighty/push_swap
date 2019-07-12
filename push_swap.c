/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:48:20 by twight            #+#    #+#             */
/*   Updated: 2019/07/12 03:53:29 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_cont		*container;

	if (argc >= 2)
	{
		container = parser(argc, argv);
		init_sort(container);
		quicksort(container);
	}
	return (0);
}
