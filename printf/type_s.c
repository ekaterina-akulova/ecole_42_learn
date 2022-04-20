/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:52:43 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:52:48 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	helpme_8(int len, t_buffer *b, t_flags *f, char *print)
{
	if (f->b_left_aligned == 1)
	{
		if (f->count_minus > 0)
		{
			len = ft_strlen(print);
			if (f->precision < len && f->b_preci == 2)
				len = f->precision;
			if (f->b_preci == 2)
				while (*print != 0 && f->precision-- != 0)
					add_to_buffer(b, f, *print++);
			if (f->b_preci == 0)
				while (*print != 0)
					add_to_buffer(b, f, *print++);
			while (f->negative-- > len)
				add_to_buffer(b, f, ' ');
		}	
	}
	return (1);
}

char	*type_s_left(t_buffer *b, t_flags *f, char *print, char *str)
{	
	int	len;

	len = 0;
	if (helpme_8(len, b, f, print) == 0)
	{
		if (f->precision < 0)
		{
			while (f->precision--)
				add_to_buffer(b, f, *print++);
		}
		while (f->precision-- > 0)
			add_to_buffer(b, f, *print++);
	}
	while (f->width > 1)
	{
		if (f->b_zero_padding == 1)
			add_to_buffer(b, f, '0');
		else if (f->space)
			add_to_buffer(b, f, ' ');
	}
	return (str);
}

void	helpme_9(t_buffer *b, t_flags *f, char *print)
{
	while (f->width > f->to_write)
	{
		if (f->b_zero_padding == 1)
			add_to_buffer(b, f, '0');
		else if (f->dot == 1)
			add_to_buffer(b, f, *print++);
		else if (f->space == 0)
			add_to_buffer(b, f, ' ');
		else
			break ;
	}
	while (f->to_write-- > 0)
		add_to_buffer(b, f, *print++);
}

void	helpme_10(t_flags *f, int length)
{
	if (f->precision == 0)
	{
		if (f->dot)
			f->to_write = 0;
		else
			f->to_write = length;
		if (f->b_preci == 1)
			f->to_write = 0;
	}
}

char	*type_s(t_buffer *b, t_flags *f, char *print, char *str)
{
	int	length;

	if (f->b_left_aligned == 1)
		return (type_s_left(b, f, print, str));
	else
	{
		if (print == NULL)
			print = "(null)";
		length = ft_strlen(print);
		if (f->dot > 0 && (size_t)f->dot > ft_strlen(str))
			f->dot = ft_strlen(str);
		helpme_10(f, length);
		if (f->precision < 0 && length < f->precision)
			f->to_write = length;
		else if (f->precision > 0 && f->dot)
		{		
			if (f->precision < length)
				f->to_write = f->precision;
			else
				f->to_write = length;
		}
		helpme_9(b, f, print);
		return (str);
	}
}
