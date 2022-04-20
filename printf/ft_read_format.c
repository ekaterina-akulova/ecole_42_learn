/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:51:10 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:51:12 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

void	read_flags(t_flags *flags, char *str, int *i)
{
	while (helpme(str, i) == 1)
	{
		helpme_2(flags, str, i);
		helpme_3(flags, str, i);
	}
}

void	width_precision(t_flags *flags, char *str, int *i)
{
	*i = 0;
	helpme_4(flags, str, i);
	helpme_5(flags, str, i);
	helpme_6(flags, str, i);
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

char	*placeholders(t_flags *flags, char *str)
{
	int	i;

	i = 0;
	read_flags(flags, str, &i);
	width_precision(flags, str, (&i));
	if (ft_is_type(str[i]))
		return (str + i);
	else
		return (str - 1);
}

char	*read_format(t_buffer *buff, t_flags *flags, char *str)
{
	str++;
	str = placeholders(flags, str);
	if (*str == '%' || *str == 'c')
	{
		if (*str == '%')
			str = type_c(buff, flags, '%', str) + 1;
		else if (*str == 'c')
			str = type_c(buff, flags, va_arg(buff->args, int), str) + 1;
	}	
	else if (*str == 's')
		str = type_s(buff, flags, va_arg(buff->args, char *), str) + 1;
	else if (*str == 'd' || *str == 'i')
		str = type_di1(buff, flags, va_arg(buff->args, int), str) + 1;
	else if (*str == 'u')
		str = type_u(buff, flags, va_arg(buff->args, unsigned int), str) + 1;
	else if (*str == 'x' || *str == 'X')
		str = type_x(buff, flags, va_arg(buff->args, unsigned int), str) + 1;
	else if (*str == 'p')
		str = type_p(buff, flags, \
			va_arg(buff->args, unsigned long int), str) + 1;
	return (str);
}
