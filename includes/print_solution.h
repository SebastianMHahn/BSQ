/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 12:56:36 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 14:01:00 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_SOLUTION_H
# define PRINT_SOLUTION_H

# include "structs.h"

void	add_solution(char **field, t_solution *solution, t_legend *legend);
void	print_field(char **field, t_dim *dim);

#endif
