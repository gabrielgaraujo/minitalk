/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:49:18 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/10/09 01:03:09 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

static int	update_line_and_return(char **line, char *buffer)
{
	*line = append_to_line(*line, buffer);
	if (has_newline(buffer))
		return (1);
	return (0);
}

static int	read_to_buffer(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*process_buffer(int fd, char **buffer, char **line)
{
	while (1)
	{
		if (read_to_buffer(fd, *buffer) == -1)
			return (free(*buffer), *buffer = NULL, free(*line), NULL);
		if (update_line_and_return(line, *buffer))
			return (*line);
		else if (ft_strlen(*buffer) < BUFFER_SIZE)
			return (free(*buffer), *buffer = NULL, *line);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (!buffer)
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else if (has_newline(buffer))
	{
		buffer = update_buffer(buffer);
		if (update_line_and_return(&line, buffer))
			return (line);
	}
	if (!buffer)
		return (free(line), NULL);
	return (process_buffer(fd, &buffer, &line));
}
