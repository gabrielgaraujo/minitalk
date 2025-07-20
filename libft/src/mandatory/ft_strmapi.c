/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:30:05 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/10 00:07:39 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	idx;

	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		str[idx] = f(idx, str[idx]);
		idx++;
	}
	return (str);
}
