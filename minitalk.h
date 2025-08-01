/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:17:44 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/07/20 11:32:34 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct s_server_data
{
	char	current_char;
	int		bit_count;
	pid_t	client_pid;
}	t_server_data;

#endif
