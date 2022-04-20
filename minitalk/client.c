/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:17:18 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/13 22:17:26 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/10/22.
//
#include "minitalk.h"

static void	sig(int signal)
{
	(void) signal;
}

int	string_to_server(unsigned char string, int pid)
{
	char	char_bits;

	char_bits = 0;
	while (char_bits < 8)
	{
		if ((string >> char_bits) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		signal(SIGUSR1, sig);
		pause();
		char_bits++;
		usleep(500);
	}
	return (1);
}

void	sig_handler(char *s_pid, unsigned char *str)
{
	int	pid;
	int	counter;

	counter = -1;
	pid = ft_atoi(s_pid);
	while (str[++counter])
	{
		if (string_to_server(str[counter], pid) != 1)
		{
			ft_putstr_fd("BAD ACCESS\n", 1);
			exit(-1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		sig_handler(argv[1], (unsigned char *)argv[2]);
	else
		ft_putstr_fd("Run the program with correct args.🤡\n", 1);
}
