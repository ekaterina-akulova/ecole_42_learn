/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:51:45 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:51:47 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helpme_7(t_buffer *b, t_flags *f, int c)
{
	if (f->b_left_aligned == 1)
	{
		if (f->b_left_aligned--)
			add_to_buffer(b, f, c);
		while (f->negative-- > 1)
			add_to_buffer(b, f, ' ');
	}
	if (!f->dot)
		f->to_write = 1;
	f->precision = f->to_write;
	if (f->b_left_aligned)
	{
		add_to_buffer(b, f, c);
		if (f->count_minus >= 1)
			while (f->negative--)
				add_to_buffer(b, f, ' ');
		if (f->count_minus >= 1)
		{
			while (f->count_minus--)
				add_to_buffer(b, f, ' ');
		}
	}
}

char	*type_c(t_buffer *b, t_flags *f, int c, char *str)
{
	if (f->b_zero_padding || f->b_left_aligned || f->dot || f->hash \
		|| f->plus || f->space || f->negative || f->precision || f->width)
	{
		helpme_7(b, f, c);
		while (f->width > 1)
		{
			if (f->b_zero_padding)
				add_to_buffer(b, f, '0');
			add_to_buffer(b, f, ' ');
		}
		if ((f->width-- && f->width >= 0) || *str == '.')
		{
			while (f->precision--)
				add_to_buffer(b, f, c);
		}
	}
	else
		add_to_buffer(b, f, c);
	return (str);
}
