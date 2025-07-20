/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:28:29 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/09 19:19:46 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	multiplier;

	multiplier = ((n >= 0) * 2) - 1;
	if (multiplier == -1)
		ft_putchar_fd('-', fd);
	if (n / 10)
		ft_putnbr_fd((n / 10) * multiplier, fd);
	ft_putchar_fd((n % 10 * multiplier) + '0', fd);
}
