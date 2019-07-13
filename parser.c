/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhmetsha <akhmetsha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:45:26 by twight            #+#    #+#             */
/*   Updated: 2019/07/13 18:05:11 by akhmetsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_options(char **argv, t_cont *c)
{
	int		i;

	i = 1;
	if (argv[i][0] == '-')
	{
		if (argv[i][1] == 'f')
			c->opt.f = TRUE;
		else if (argv[i][1] == 'c')
			c->opt.c = TRUE;
		else if (argv[i][1] == 't')
			c->opt.t = TRUE;
		else
			terminate(ERR_WRONG_OPTION);
		i++;
	}
	if ((c->opt.f == 1 || c->opt.c == 1 || c->opt.t == 1) && argv[i][0] == '-')
	{
		if (argv[i][1] == 'f')
			c->opt.f = TRUE;
		else if (argv[i][1] == 'c' && c->opt.f != TRUE)
			c->opt.c = TRUE;
		else if (argv[i][1] == 't')
			c->opt.t = TRUE;
		else
			terminate(ERR_WRONG_OPTION);
		i++;
	}
	return (i);
}

/*
** If the numbers were sent as separate arguments of argv, parses them and
** creates stack nodes filled with the obtained values.
*/

static void	parse_arr(t_cont *cont, int argc, char **argv)
{
	int	i;

	i = parse_options(argv, cont);
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
	cont->opt.f = FALSE;
	cont->opt.c = FALSE;
	cont->opt.t = FALSE;
	cont->fd == 0 ? cont->fd = 1 : cont->fd;
	if (argc == 2 && !ft_isnum(argv[1], 10)) //) || !ft_isalpha(argv[1][1]
		parse_str(cont, argv[1]);
	else
		parse_arr(cont, argc, argv);
	if (cont->a_size < 2)
		terminate(ERR_NO_NUMBERS);
	return (cont);
}
