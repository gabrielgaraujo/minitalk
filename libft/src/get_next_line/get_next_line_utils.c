/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:26 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/10/09 00:09:20 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	count_to_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*initialize_new_line(char *line, int size)
{
	char	*new_line;
	int		i;

	if (size == 0)
		return (free(line), NULL);
	new_line = malloc(size + 1);
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

char	*append_to_line(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*new_line;
	int		new_line_size;

	if (!buffer)
		return (line);
	new_line_size = ft_strlen(line) + count_to_newline(buffer);
	new_line = initialize_new_line(line, new_line_size);
	if (new_line == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(new_line);
	while (buffer && buffer[i] && buffer[i] != '\n')
		new_line[j++] = buffer[i++];
	if (buffer && buffer[i] == '\n')
		new_line[j++] = buffer[i++];
	new_line[j] = '\0';
	return (new_line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	i++;
	new_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (new_buffer == NULL)
		return (NULL);
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	new_buffer[j] = '\0';
	return (new_buffer);
}
