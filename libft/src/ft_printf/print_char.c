/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:03:43 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:23 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(const char **str, va_list args, int *printed_chars)
{
	char	character;

	if (**str != 'c')
		return ;
	character = va_arg(args, int);
	ft_putchar_fd(character, 1);
	*printed_chars += 1;
}
