/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:18:04 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:24 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(const char **str, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	(*str)++;
	print_char(str, args, &printed_chars);
	print_string(str, args, &printed_chars);
	print_integer(str, args, &printed_chars);
	print_percentage(str, &printed_chars);
	print_hex(str, args, &printed_chars);
	print_pointer(str, args, &printed_chars);
	return (printed_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			printed_chars += handle_specifier(&str, args);
		else
			ft_putchar_fd(*str, 1);
		printed_chars += 1;
		str++;
	}
	va_end(args);
	return (printed_chars);
}
