/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 12:34:05 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 13:54:57 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"
#include "structs.h"

void	add_solution(char **field, t_solution *solution, t_legend *legend)
{
	int y;
	int x;

	y = solution->y;
	while (y <= solution->size + solution->y)
	{
		x = solution->x;
		while (x <= solution->size + solution->x)
		{
			field[y][x] = legend->full;
			x++;
		}
		y++;
	}
}

void	print_field(char **field, t_dim *dim)
{
	int y;
	int x;

	y = 0;
	while (y < dim->rows)
	{
		x = 0;
		while (x < dim->columns)
		{
			ft_putchar(field[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
