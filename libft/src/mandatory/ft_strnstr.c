/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:15:42 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/07 19:22:09 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_length;
	char	*search_str;
	int		has_enough_space;
	int		is_same_string;

	little_length = ft_strlen(little);
	search_str = (char *) big;
	if (!little_length)
		return (search_str);
	while (*search_str && len > 0)
	{
		has_enough_space = little_length <= len;
		is_same_string = ft_strncmp(search_str, little, little_length) == 0;
		if (has_enough_space && is_same_string)
			return (search_str);
		search_str++;
		len--;
	}
	return (NULL);
}
