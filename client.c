/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:17:44 by gaaraujo          #+#    #+#             */
/*   Updated: 2025/07/30 00:00:00 by gaaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	handle_acknowledgment(int signal)
{
	(void)signal;
	g_ack_received = 1;
}

static void	send_signal_and_wait(pid_t pid, int signal_type)
{
	int	timeout_counter;

	g_ack_received = 0;
	if (signal_type)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	timeout_counter = 0;
	while (!g_ack_received && timeout_counter < 1000)
	{
		usleep(500);
		timeout_counter++;
	}
	if (!g_ack_received)
	{
		ft_printf("Error: Timeout waiting for acknowledgment\n");
		exit(1);
	}
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_signal_and_wait(pid, (c >> i) & 1);
		i--;
	}
}

static void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	if (argc != 3)
		return (ft_printf("Usage: %s <pid> <message>\n", argv[0]), 1);
	sa.sa_handler = handle_acknowledgment;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Invalid PID\n"), 1);
	ft_printf("Sending: %s\n", argv[2]);
	send_string(pid, argv[2]);
	ft_printf("Done!\n");
	return (0);
}
