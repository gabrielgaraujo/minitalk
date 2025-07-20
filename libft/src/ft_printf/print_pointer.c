/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:15:36 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:18 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(const char **str, va_list args, int *printed_chars)
{
	unsigned long long	pointer;

	if (**str != 'p')
		return ;
	pointer = va_arg(args, unsigned long int);
	if (pointer == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*printed_chars += 5;
		return ;
	}
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	*printed_chars += 2;
	convert_hex(pointer, 87, printed_chars);
}
