/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 13:56:33 by nloomans       #+#    #+#                */
/*   Updated: 2019/02/27 13:53:28 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 256

/*
** Increase the size of `output` by re-allocating with a larger capacity.
*/

void	ft_realloc(char **output, int old_capacity, int new_capacity)
{
	int		i;
	char	*new_output;

	new_output = malloc(sizeof(char) * new_capacity);
	i = 0;
	while (i < old_capacity)
	{
		new_output[i] = (*output)[i];
		i++;
	}
	free(*output);
	*output = new_output;
}

/*
** Append `to_append` to `output` and update `output_length`.
*/

void	append(char *output, int *output_length, char *to_append,
		int to_append_length)
{
	int		i;

	i = 0;
	while (i < to_append_length)
	{
		output[*output_length + i] = to_append[i];
		i++;
	}
	*output_length = *output_length + to_append_length;
}

/*
** Read the entire program input. Store it in a sufficiently large buffer.
** Return the buffer.
**
** This also appends a \0 byte at the end of output. The +1 in the
** output_length + bytes_read + 1 > output_capacity check is there to ensure
** that there is always enough space to add the \0 byte at the end.
*/

char	*read_fd(int fd)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*output;
	int		output_length;
	int		output_capacity;

	output_length = 0;
	output_capacity = 256;
	output = malloc(sizeof(char) * output_capacity);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		if (output_length + bytes_read + 1 > output_capacity)
		{
			ft_realloc(&output, output_capacity, output_capacity * 2);
			output_capacity *= 2;
		}
		append(output, &output_length, buffer, bytes_read);
	}
	append(output, &output_length, "\0", 1);
	return (output);
}

char	*read_file(char *file)
{
	int		fd;
	char	*output;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	output = read_fd(fd);
	close(fd);
	return (output);
}
