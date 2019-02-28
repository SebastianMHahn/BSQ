/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 15:49:35 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 18:45:05 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "free2d.h"
#include "read.h"
#include "structs.h"
#include "parse.h"
#include "print_solution.h"
#include "find_max_square.h"

void	solve_and_print(char **raw_input)
{
	char		**field;
	t_legend	legend;
	t_dim		dim;
	t_solution	*solution;

	if (*raw_input == NULL)
		return (ft_puterr("map error\n"));
	field = parse(&legend, &dim, *raw_input);
	free(*raw_input);
	if (field == NULL)
		return (ft_puterr("map error\n"));
	solution = char_map_to_solution(field, dim, legend);
	if (solution->size != -42)
		add_solution(field, solution, &legend);
	free(solution);
	print_field(field, &dim);
	free2d((void ***)&field, dim.rows);
}

int		main(int argc, char **argv)
{
	char	*raw_input;
	int		i;

	if (argc < 2)
	{
		raw_input = read_fd(0);
		solve_and_print(&raw_input);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			raw_input = read_file(argv[i]);
			solve_and_print(&raw_input);
			if (argc > 2)
				ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
