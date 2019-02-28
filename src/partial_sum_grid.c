/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   partial_sum_grid.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 20:59:54 by sehahn         #+#    #+#                */
/*   Updated: 2019/02/26 14:51:48 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "partial_sum_grid.h"

int		calc_running_sum(int **array, t_dim xy, int current)
{
	int up;
	int left;
	int up_left;

	up = 0;
	left = 0;
	up_left = 0;
	if (xy.columns > 0)
		left = array[xy.rows][xy.columns - 1];
	if (xy.rows > 0)
		up = array[xy.rows - 1][xy.columns];
	if (xy.rows > 0 && xy.columns > 0)
		up_left = array[xy.rows - 1][xy.columns - 1];
	return (current + left + up - up_left);
}

int		**partial_sum_grid(char **map, t_dim dim, t_legend legend)
{
	t_dim	xy;
	int		current;
	int		**array;

	xy.rows = 0;
	array = malloc(sizeof(int *) * dim.rows);
	while (xy.rows < dim.rows)
	{
		xy.columns = 0;
		array[xy.rows] = malloc(sizeof(int) * dim.columns);
		while (xy.columns < dim.columns)
		{
			current = 0;
			if (map[xy.rows][xy.columns] == legend.obstacle)
				current = 1;
			array[xy.rows][xy.columns] = calc_running_sum(array, xy, current);
			xy.columns++;
		}
		xy.rows++;
	}
	return (array);
}
