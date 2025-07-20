/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:14:30 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/11/16 15:22:38 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	is_lowercase;
	int	is_uppercase;

	is_lowercase = c >= 'a' && c <= 'z';
	is_uppercase = c >= 'A' && c <= 'Z';
	return (is_lowercase || is_uppercase);
}
