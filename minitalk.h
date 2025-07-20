/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:17:44 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/07/20 11:17:52 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

/*
** ============================================================================
** FUNCTION PROTOTYPES
** ============================================================================
*/

void	signal_handler(int sig, siginfo_t *info, void *context);
void	send_char(pid_t pid, char c);
void	send_string(pid_t pid, char *str);

#endif
