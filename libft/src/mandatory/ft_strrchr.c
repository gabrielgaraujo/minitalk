/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:51:19 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/11/20 23:00:18 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
		ptr++;
	while (ptr != s)
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr--;
	}
	if (*ptr == (char) c)
		return (ptr);
	return (NULL);
}
