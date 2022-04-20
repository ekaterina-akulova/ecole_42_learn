/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:25:40 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 21:25:42 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/21/22.
//

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || \
		c == '\f' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_etoi(const char *str, t_stack *stack)
{
	int					i;
	int					sign;
	int					res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (*str && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (i > 0 && res > (res * 10 + (str[i + 1] - 48)))
			ft_error(stack);
		i++;
	}
	res *= sign;
	return (res);
}
