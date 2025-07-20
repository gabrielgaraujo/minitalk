/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:15:13 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/11 22:54:00 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	word_length;
	int	count;

	count = 0;
	while (*str != '\0' && ft_strchr(str, delimiter))
	{
		word_length = ft_strchr(str, delimiter) - str;
		if (word_length >= 1)
			count++;
		str += word_length + (delimiter != '\0');
	}
	if (*str && *str != delimiter)
		count++;
	return (count);
}

static bool	allocate_array(char ***array, int word_count)
{
	*array = (char **) malloc(sizeof(char *) * (word_count + 1));
	return (*array != NULL);
}

static bool	populate_array(char **array, const char	*str, char delimiter)
{
	int	word_length;
	int	idx;

	idx = 0;
	while (*str != '\0' && ft_strchr(str, delimiter))
	{
		word_length = ft_strchr(str, delimiter) - str;
		if (word_length >= 1)
		{
			array[idx] = ft_substr(str, 0, word_length);
			if (array[idx++] == NULL)
				return (false);
		}
		str += word_length + (delimiter != '\0');
	}
	if (*str && *str != delimiter)
	{
		array[idx] = ft_substr(str, 0, ft_strlen(str));
		if (array[idx++] == NULL)
			return (NULL);
	}
	array[idx] = NULL;
	return (true);
}

static void	deallocate_memory(char ***array)
{
	int	idx;

	idx = 0;
	while ((*array)[idx])
	{
		free((*array)[idx]);
		(*array)[idx++] = NULL;
	}
	free(*array);
	*array = NULL;
}

char	**ft_split(char const *s, char delimiter)
{
	char	**array;
	int		word_count;

	word_count = count_words(s, delimiter);
	if (!allocate_array(&array, word_count))
		return (NULL);
	if (!populate_array(array, s, delimiter))
		deallocate_memory(&array);
	else
		array[word_count] = NULL;
	return (array);
}
