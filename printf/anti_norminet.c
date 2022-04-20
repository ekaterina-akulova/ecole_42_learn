/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_norminet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:26:17 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/13 15:26:20 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helpme_2(t_flags *flags, char *str, int *i)
{
	if (str[*i] == '0')
	{
		flags->b_zero_padding = 1;
		(*i)++;
	}
	else if (str[*i] == '-')
	{
		flags->b_left_aligned = 1;
		flags->count_minus++;
		(*i)++;
	}
	else if (str[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
	}
}

void	helpme_3(t_flags *flags, char *str, int *i)
{
	if (str[*i] == '#')
	{
		flags->hash = 1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		flags->plus = 1;
		(*i)++;
	}
	else if (str[*i] == ' ')
	{
		flags->space = 1;
		(*i)++;
	}
}

void	helpme_4(t_flags *flags, char *str, int *i)
{
	while (str[*i] == ' ')
	{
		(*i)++;
		flags->countspace++;
	}
	while (str[*i] == '-')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			flags->negative = flags->negative * 10 + str[*i] - '0';
			(*i)++;
		}
	}
}

void	helpme_5(t_flags *flags, char *str, int *i)
{
	while (str[*i] == '+')
	{
		(*i)++;
		flags->count_plus++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			flags->precision = flags->precision * 10 + str[*i] - '0';
			(*i)++;
		}
		if (ft_is_type(str[*i]))
			flags->b_preci = 2;
		else if (str[*i] == '0')
			flags->b_preci = 1;
	}
}

void	helpme_6(t_flags *flags, char *str, int *i)
{
	if (str[*i] == '#')
		(*i)++;
	 if ((str[*i] >= '0' && str[*i] <= '9'))
	{
		while ((str[*i] >= '0' && str[*i] <= '9'))
		{
			flags->width = flags->width * 10 + str[*i] - '0';
			(*i)++;
		}
	}
}
