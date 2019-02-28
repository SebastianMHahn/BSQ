/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 17:46:43 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 14:01:45 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structs.h"

char	**parse(t_legend *legend, t_dim *dim, char *input);

#endif
