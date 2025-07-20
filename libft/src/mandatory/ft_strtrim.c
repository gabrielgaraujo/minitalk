/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:41:26 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/10 00:01:37 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start_ptr;
	char	*end_ptr;
	int		lenght;
	char	*str;

	start_ptr = (char *) s1;
	end_ptr = (char *) &s1[ft_strlen(s1) - 1];
	while (ft_strchr(set, *start_ptr) != NULL && *start_ptr)
		start_ptr++;
	if (start_ptr >= end_ptr)
		return (ft_strdup(""));
	while (ft_strrchr(set, *end_ptr) != NULL)
		end_ptr--;
	lenght = end_ptr - start_ptr + 1;
	str = ft_substr(start_ptr, 0, lenght);
	return (str);
}
