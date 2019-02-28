/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free2d.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 13:05:51 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 14:00:50 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free2d(void ***to_free, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		free((*to_free)[i]);
		i++;
	}
	free(*to_free);
}
