/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:49:45 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:49:50 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_buffer	buff;
	t_flags		flags;
	char		*str;

	str = (char *)s;
	ft_bzero(&buff, sizeof(buff));
	va_start(buff.args, s);
	while (*str)
	{
		if (*str == '%')
		{
			ft_bzero(&flags, sizeof(flags));
			str = read_format(&buff, &flags, str);
		}
		else
			add_to_buffer(&buff, &flags, *str++);
	}
	write(1, buff.buffer, buff.buff_i);
	va_end(buff.args);
	return (buff.buff_i + buff.written);
}
