/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:50:49 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/11/17 21:12:12 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*casted_dst;
	const char	*casted_src;

	casted_dst = (char *) dst;
	casted_src = (const char *) src;
	if (!dst && !src)
		return (NULL);
	if (casted_dst < casted_src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			casted_dst[len] = casted_src[len];
	}
	return (dst);
}
