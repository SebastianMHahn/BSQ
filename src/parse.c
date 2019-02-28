/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 16:23:27 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 16:30:24 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "ft.h"
#include "structs.h"

int		get_number(char *str, int length)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	if (str[index] == '+')
		index++;
	while (index < length)
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		nb *= 10;
		nb += str[index] - 48;
		index++;
	}
	return (nb);
}

int		consume_first_row(t_legend *legend, int *rows, char *input, int *index)
{
	int		newline_pos;

	newline_pos = ft_find_char(input, '\n');
	if (newline_pos < 4)
		return (0);
	*rows = get_number(input, newline_pos - 3);
	legend->empty = input[newline_pos - 3];
	legend->obstacle = input[newline_pos - 2];
	legend->full = input[newline_pos - 1];
	if (legend->empty == legend->obstacle)
		return (0);
	*index = newline_pos;
	return (1);
}

int		validate_line(char *input, t_legend *legend, int *index)
{
	int		line_start_index;

	line_start_index = *index;
	while (input[*index] != '\n')
	{
		if (input[*index] != legend->empty && input[*index] != legend->obstacle)
			return (0);
		(*index)++;
	}
	return (*index - line_start_index);
}

int		validate(int *columns, char *input, t_legend *legend, int expected_rows)
{
	int		index;
	int		rows;
	int		line_length;

	index = 0;
	rows = 0;
	*columns = 0;
	if (input[index] != '\n')
		return (0);
	index++;
	while (input[index] != '\0')
	{
		line_length = validate_line(input, legend, &index);
		if (line_length <= 0)
			return (line_length);
		if (*columns == 0)
			*columns = line_length;
		else if (*columns != line_length)
			return (0);
		index++;
		rows++;
	}
	return (rows == expected_rows && rows > 0 && *columns > 0);
}

/*
** Parse raw_map to standard format. Returns NULL on invalid map.
*/

char	**parse(t_legend *legend, t_dim *dim, char *input)
{
	char	**output;
	int		index;
	int		y;
	int		x;

	index = 0;
	if (!consume_first_row(legend, &dim->rows, input, &index) ||
		!validate(&dim->columns, input + index, legend, dim->rows))
		return (NULL);
	index++;
	output = malloc(sizeof(char*) * dim->rows);
	y = 0;
	while (y < dim->rows)
	{
		output[y] = malloc(sizeof(char) * dim->columns);
		x = 0;
		while (x < dim->columns)
			output[y][x++] = input[index++];
		y++;
		index++;
	}
	return (output);
}
