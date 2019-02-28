/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 17:42:05 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/25 18:45:22 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct	s_legend
{
	char empty;
	char obstacle;
	char full;
};
typedef struct s_legend		t_legend;

struct	s_dim
{
	int rows;
	int columns;
};
typedef struct s_dim		t_dim;

struct	s_solution
{
	int x;
	int y;
	int size;
};
typedef struct s_solution	t_solution;

#endif
