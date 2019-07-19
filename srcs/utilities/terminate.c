/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 00:01:05 by twight            #+#    #+#             */
/*   Updated: 2019/07/20 01:00:51 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Added exit (1) in the case of ERR_NO_NUMBERS in order to respect the Norm.
** Still, I personally believe that the program shall show the error message
** if the only value is present.
*/

void	terminate(short program, const char *str)
{
	if (str == ERR_NO_NUMBERS)
		exit(1);
	if (program == PUSH)
		ft_putstr("push_swap: ");
	else if (program == CHECK)
		ft_putstr("checker: ");
	ft_putendl(str);
	exit(1);
}
