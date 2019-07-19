/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:45:26 by twight            #+#    #+#             */
/*   Updated: 2019/07/19 23:35:07 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** If flag -f is specified, tries to open the file with the specified name.
** Otherwise, forces the program to quit.
*/

static int	parse_filename(char **argv, t_cont *c, char type)
{
	int i;

	if (type == 'a')
		i = 2;
	else if (type == 's')
		i = 1;
	if (c->opt.f == TRUE && c->opt.c == FALSE && c->opt.t == FALSE)
	{
		if ((c->fd = open(argv[i], O_RDONLY)) == -1)
			terminate(c->program, ERR_FILENAME);
		return (1);
	}
	else if (c->opt.f == TRUE && (c->opt.c == TRUE || c->opt.t == TRUE))
	{
		if ((c->fd = open(argv[++i], O_RDONLY)) == -1)
			terminate(c->program, ERR_FILENAME);
		return (1);
	}
	else if (c->opt.f == FALSE)
		c->fd = 1;
	return (0);
}

/*
** Checks if any option flags are present.
*/

static int	parse_options(char **argv, t_cont *c, int i, char type)
{
	while ((i <= 4 && type == 'a') || (i <= 3 && type == 's'))
	{
		if ((argv[i][0] == '-' && ft_isalpha(argv[i][1]) && \
		((i == 0 && type == 's') || i == 1 || \
		(i == 2 && (c->opt.f + c->opt.c + c->opt.t + c->opt.v == 1)) || \
		(i == 3 && (c->opt.f + c->opt.c + c->opt.t + c->opt.v == 2)))))
		{
			if (argv[i][1] == 'f')
				c->opt.f = TRUE;
			else if (argv[i][1] == 'c' && (c->program == CHECK || \
			(c->opt.f != TRUE && c->program == PUSH)))
				c->opt.c = TRUE;
			else if (argv[i][1] == 't' && c->program == PUSH)
				c->opt.t = TRUE;
			else if (argv[i][1] == 'v')
				c->opt.v = TRUE;
			else
				terminate(c->program, ERR_WR_FLAG);
			i++;
		}
		else
			break ;
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

	i = parse_options(argv, cont, 1, 'a');
	if (cont->program == CHECK && cont->opt.f == TRUE)
		i += parse_filename(argv, cont, 'a');
	while (i < argc)
	{
		if (!ft_isint(argv[i], 0))
			terminate(cont->program, ERR_NAN);
		add(&(A_FIRST), &(A_LAST), ft_atoi(argv[i++]), cont->program);
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
	i = parse_options(numbers, cont, 0, 's');
	if (cont->program == CHECK && cont->opt.f == TRUE)
		i += parse_filename(numbers, cont, 's');
	while (numbers[i])
	{
		if (!ft_isint(numbers[i], 0))
			terminate(cont->program, ERR_NAN);
		add(&(A_FIRST), &(A_LAST), ft_atoi(numbers[i++]), cont->program);
		cont->a_size++;
	}
	ft_strsplit_free(&numbers);
}

/*
** Initializes a stack, sends argv(s) to the functions which parse them.
*/

t_cont		*parser(int argc, char **argv, short program)
{
	t_cont	*cont;

	if (!(cont = (t_cont *)ft_memalloc(sizeof(t_cont))))
		terminate(program, ERR_MEMALLOC);
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
	cont->opt.v = FALSE;
	cont->program = program;
	if (argc == 2 && !ft_isnum(argv[1], 10))
		parse_str(cont, argv[1]);
	else
		parse_arr(cont, argc, argv);
	if (cont->a_size < 2)
		terminate(program, ERR_NO_NUMBERS);
	return (cont);
}
