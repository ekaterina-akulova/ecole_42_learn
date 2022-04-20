/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:17:34 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/13 22:17:36 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/10/22.
//

#include "minitalk.h"

static t_data	g_data;

static void	bit_on_handler(int signo, siginfo_t *si, void *data)
{
	(void) data;
	g_data.sym = g_data.sym + ((signo & 1) << g_data.size);
	g_data.size++;
	if (g_data.size == 8)
	{
		write(1, &g_data.sym, 1);
		g_data.size = 0;
		g_data.sym = 0;
	}
	if (kill(si->si_pid, SIGUSR1) == -1)
		ft_putstr_fd("BAD ACCESS\n", 1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = 0;
	sa.sa_sigaction = bit_on_handler;
	g_data.sym = 0;
	g_data.size = 0;
	g_data.pid = getpid();
	if (g_data.pid != 0)
	{
		ft_putstr_fd("PID = ", 1);
		ft_putnbr_fd(g_data.pid, 1);
		write(1, "\n", 1);
	}
	else
		ft_putstr_fd("PID IS BAD. Try again.\n", 1);
	while (1)
	{
		sigaction(SIGUSR2, &sa, 0);
		sigaction(SIGUSR1, &sa, 0);
		pause();
	}
}
