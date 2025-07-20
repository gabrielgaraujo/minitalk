/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:03:53 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/07 18:13:16 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casted_s1;
	unsigned char	*casted_s2;

	casted_s1 = (unsigned char *) s1;
	casted_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (*casted_s1 != *casted_s2)
			return (*casted_s1 - *casted_s2);
		casted_s1++;
		casted_s2++;
		n--;
	}
	return (*casted_s1 - *casted_s2);
}
