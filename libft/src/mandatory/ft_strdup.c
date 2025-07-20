/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:39:28 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/08 17:44:15 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		str_size;

	str_size = ft_strlen(s) + 1;
	str = (char *) malloc(sizeof(char) * str_size);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, str_size);
	return (str);
}
