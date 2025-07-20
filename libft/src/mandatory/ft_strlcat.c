/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:31:18 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/07 17:48:13 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_initial_length;

	dst_initial_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_initial_length >= dstsize)
		return (src_length + dstsize);
	while (*dst)
		dst++;
	while (*src && dstsize - dst_initial_length - 1 > 0)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (src_length + dst_initial_length);
}
