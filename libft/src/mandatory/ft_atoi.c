/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:25:32 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/12/08 15:23:09 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_whitespaces(char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
}

static void	set_multiplier(int *multiplier, char **str)
{
	if (**str != '-' && **str != '+')
		return ;
	if (**str == '-')
		*multiplier = -1;
	(*str)++;
}

int	ft_atoi(const char *nptr)
{
	char	*number_str;
	int		multiplier;
	long	result;

	number_str = (char *) nptr;
	multiplier = 1;
	result = 0;
	skip_whitespaces(&number_str);
	if (*number_str == '-' || *number_str == '+')
		set_multiplier(&multiplier, &number_str);
	while (ft_isdigit(*number_str))
	{
		result = result * 10 + (*number_str - '0');
		if (result > 2147483647 && multiplier == 1)
			return (2147483647);
		if (result > 2147483648 && multiplier == -1)
			return (-2147483648);
		number_str++;
	}
	return ((int)(result * multiplier));
}
