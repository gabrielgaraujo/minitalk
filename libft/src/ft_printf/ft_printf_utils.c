/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:51:00 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:25 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_putnbr(long long n, int *printed_chars)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		*printed_chars += 1;
		printf_putnbr(-n, printed_chars);
	}
	else if (n >= 10)
	{
		printf_putnbr(n / 10, printed_chars);
		ft_putchar_fd(n % 10 + '0', 1);
		*printed_chars += 1;
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*printed_chars += 1;
	}
}
