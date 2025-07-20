/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:47:12 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/08 19:18:34 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_length;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start || len == 0)
		str = ft_strdup("");
	else
	{
		str_length = s_len - start;
		if (str_length > len)
			str_length = len;
		str = (char *) malloc(sizeof(char) * (str_length + 1));
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, &s[start], str_length);
		str[str_length] = '\0';
	}
	return (str);
}
