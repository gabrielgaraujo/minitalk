/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:19:32 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/11/20 22:30:32 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	is_uppercase;

	is_uppercase = c >= 'A' && c <= 'Z';
	if (!ft_isalpha(c) || is_uppercase)
		return (c);
	else
		return (c - 32);
}
