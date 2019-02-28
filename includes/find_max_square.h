/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_max_square.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 11:05:51 by sehahn         #+#    #+#                */
/*   Updated: 2019/02/26 14:48:32 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_MAX_SQUARE_H
# define FIND_MAX_SQUARE_H
# include "structs.h"

int			is_possible(int **array, t_dim xy, t_dim dim, int max_size);
int			*find_max_square(int **array, t_dim dim);
t_solution	*char_map_to_solution(char **map, t_dim dim, t_legend legend);

#endif
