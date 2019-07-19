/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 00:01:05 by twight            #+#    #+#             */
/*   Updated: 2019/07/19 19:40:07 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(short program, const char *str)
{
	if (program == PUSH)
		ft_putstr("push_swap: ");
	else if (program == CHECK)
		ft_putstr("checker: ");
	ft_putendl(str);
	exit(1);
}
