/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:04:56 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:17 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(const char **str, va_list args, int *printed_chars)
{
	char	*string;

	if (**str != 's')
		return ;
	string = va_arg(args, char *);
	if (!string)
		string = "(null)";
	ft_putstr_fd(string, 1);
	*printed_chars += ft_strlen(string);
}
