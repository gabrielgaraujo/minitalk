/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:24:11 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/08 19:38:48 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		s1_length;
	int		s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	size = s1_length + s2_length + 1;
	str = (char *) malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, s1_length);
	ft_memcpy(&str[s1_length], s2, s2_length + 1);
	return (str);
}
