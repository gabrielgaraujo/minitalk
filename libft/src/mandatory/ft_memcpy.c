/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:04:01 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/05 10:39:51 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*casted_dst;
	const char	*casted_src;

	if (!dst && !src)
		return (NULL);
	casted_dst = (char *) dst;
	casted_src = (const char *) src;
	while (n--)
		*casted_dst++ = *casted_src++;
	return (dst);
}
