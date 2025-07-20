/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:28:38 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/08 21:29:52 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	digit_to_char(int n)
{
	char	digit;

	digit = '0';
	if (n < 0)
		digit -= n % 10;
	else
		digit += n % 10;
	return (digit);
}

static void	fill_str(char *str, int n, int length)
{
	str[length--] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n / 10 != 0)
	{
		str[length--] = digit_to_char(n % 10);
		n /= 10;
	}
	str[length] = digit_to_char(n);
}

char	*ft_itoa(int n)
{
	int		length;
	int		is_negative;
	char	*str;

	is_negative = n < 0;
	length = is_negative;
	length += count_digits(n);
	str = (char *) malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (NULL);
	fill_str(str, n, length);
	return (str);
}
