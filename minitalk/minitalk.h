/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:18:19 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/13 22:18:21 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/7/22.
//

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <wchar.h>
# include "my_libft/libft.h"

typedef struct s_data
{
	size_t			size;
	unsigned char	sym;
	pid_t			pid;
}				t_data;

int		string_to_server(unsigned char string, int pid);
void	sig_handler(char *s_pid, unsigned char *str);

#endif
