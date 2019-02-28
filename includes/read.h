/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 15:48:30 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 14:01:29 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

char	*read_fd(int fd);
char	*read_file(char *path);

#endif
