/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:31:17 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/11/20 22:32:07 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	is_lowercase;

	is_lowercase = c >= 'a' && c <= 'z';
	if (!ft_isalpha(c) || is_lowercase)
		return (c);
	else
		return (c + 32);
}
