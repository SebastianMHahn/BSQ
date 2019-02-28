/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_max_square.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 21:00:31 by sehahn         #+#    #+#                */
/*   Updated: 2019/02/27 13:22:36 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "free2d.h"
#include "partial_sum_grid.h"

/*
** this function checks whether it is possible to place a square at postion xy
** with size max_size without hitting an obstacle or going over the edges of
** the map.
*/

int				is_possible(int **array, t_dim xy, t_dim dim, int max_size)
{
	int	top_left;
	int top_right;
	int bottom_left;
	int bottom_right;

	if (((xy.rows + max_size) >= dim.rows) ||
			((xy.columns + max_size) >= dim.columns))
		return (0);
	top_left = 0;
	top_right = 0;
	bottom_left = 0;
	bottom_right = array[xy.rows + max_size][xy.columns + max_size];
	if (xy.columns > 0)
		bottom_left = array[xy.rows + max_size][xy.columns - 1];
	if (xy.rows > 0)
		top_right = array[xy.rows - 1][xy.columns + max_size];
	if (xy.rows > 0 && xy.columns > 0)
		top_left = array[xy.rows - 1][xy.columns - 1];
	return (bottom_right - top_right - bottom_left + top_left == 0);
}

/*
** This function finds the maximum sized square that is closest to the top left
** corner of the map. It iteratively checks for squares of increasing sizes.
*/

t_solution		*find_max_square(int **array, t_dim dim)
{
	t_solution	*solution;
	int			max_size;
	t_dim		xy;

	xy.rows = 0;
	max_size = 0;
	solution = malloc(sizeof(t_solution));
	solution->size = -42;
	while (xy.rows < dim.rows)
	{
		xy.columns = 0;
		while (xy.columns < dim.columns)
		{
			while (is_possible(array, xy, dim, max_size) == 1)
			{
				solution->y = xy.rows;
				solution->x = xy.columns;
				solution->size = max_size;
				max_size++;
			}
			xy.columns++;
		}
		xy.rows++;
	}
	return (solution);
}

/*
** This function takes a string array representing the map as input and returns
** the maximum size square as a t_solution structure containing the x and y
** coordinates of the top left corner and the size of the square.
*/

t_solution		*char_map_to_solution(char **map, t_dim dim, t_legend legend)
{
	int			**array;
	t_solution	*solution;

	array = partial_sum_grid(map, dim, legend);
	solution = find_max_square(array, dim);
	free2d((void ***)&array, dim.rows);
	return (solution);
}
