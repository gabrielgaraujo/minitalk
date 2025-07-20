/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:08:10 by gaaraujo          #+#    #+#             */
/*   Updated: 2024/10/04 19:40:20 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

void	printf_putnbr(long long n, int *printed_chars);
int		ft_printf(const char *str, ...);
void	print_char(const char **str, va_list args, int *printed_chars);
void	print_string(const char **str, va_list args, int *printed_chars);
void	print_integer(const char **str, va_list args, int *printed_chars);
void	print_percentage(const char **str, int *printed_chars);
void	print_hex(const char **str, va_list args, int *printed_chars);
void	convert_hex(unsigned long int hex, int upcase_mod, int *printed_chars);
void	print_pointer(const char **str, va_list args, int *printed_chars);
#endif 