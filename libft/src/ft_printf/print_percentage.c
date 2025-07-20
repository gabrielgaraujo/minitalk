/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:07:35 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:19 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percentage(const char **str, int *printed_chars)
{
	if (**str != '%')
		return ;
	ft_putchar_fd('%', 1);
	*printed_chars += 1;
}
