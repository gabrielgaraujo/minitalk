/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:06:13 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:20 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_integer(const char **str, va_list args, int *printed_chars)
{
	long long	integer;

	if (**str != 'd' && **str != 'i' && **str != 'u')
		return ;
	if (**str == 'u')
	{
		integer = va_arg(args, unsigned int);
		if (integer < 0)
			integer = UINT_MAX;
	}
	else
		integer = va_arg(args, int);
	printf_putnbr(integer, printed_chars);
}
