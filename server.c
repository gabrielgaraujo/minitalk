/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:17:44 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/07/20 11:39:35 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server_data	g_server;

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	
	g_server.client_pid = info->si_pid;
	
	if (sig == SIGUSR1)
		g_server.current_char = (g_server.current_char << 1);
	else if (sig == SIGUSR2)
		g_server.current_char = (g_server.current_char << 1) | 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (g_server.current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", g_server.current_char);
		g_server.current_char = 0;
		g_server.bit_count = 0;
	}
	
	// Send acknowledgment back to client
	if (kill(g_server.client_pid, SIGUSR1) == -1)
	{
		ft_printf("Error: Failed to send acknowledgment to client\n");
		exit(1);
	}
}

static void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	g_server.current_char = 0;
	g_server.bit_count = 0;
	g_server.client_pid = 0;
	
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for messages...\n");
	setup_signal_handlers();
	while (1)
		pause();
	return (0);
}
