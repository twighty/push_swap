/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:45:26 by twight            #+#    #+#             */
/*   Updated: 2019/07/12 03:13:48 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** If the numbers were sent as separate arguments of argv, parses them and
** creates stack nodes filled with the obtained values.
*/

static void	parse_arr(t_cont *cont, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i], 0))
			terminate(ERR_NAN);
		add(&(A_FIRST), &(A_LAST), ft_atoi(argv[i++]));
		cont->a_size++;
	}
}

/*
** Parses a string, creates stack nodes and fills them with the values obtained.
*/

static void	parse_str(t_cont *cont, char *str)
{
	char	**numbers;
	size_t	i;

	numbers = ft_strsplit(str, ' ');
	i = 0;
	while (numbers[i])
	{
		if (!ft_isint(numbers[i], 0))
			terminate(ERR_NAN);
		add(&(A_FIRST), &(A_LAST), ft_atoi(numbers[i++]));
		cont->a_size++;
	}
	ft_strsplit_free(&numbers);
}

/*
** Initializes a stack, sends argv(s) to the functions which parse them.
*/

t_cont		*parser(int argc, char **argv)
{
	t_cont	*cont;

	if (!(cont = (t_cont *)ft_memalloc(sizeof(t_cont))))
		terminate(ERR_MEMALLOC);
	A_FIRST = NULL;
	B_FIRST = NULL;
	A_LAST = NULL;
	B_LAST = NULL;
	cont->index = 1;
	cont->a_size = 0;
	cont->b_size = 0;
	cont->total = 0;
	cont->options = FALSE;
	if (argc == 2 && !ft_isnum(argv[1], 10))
		parse_str(cont, argv[1]);
	else
		parse_arr(cont, argc, argv);
	if (cont->a_size < 2)
		terminate(ERR_NO_NUMBERS);
	return (cont);
}
