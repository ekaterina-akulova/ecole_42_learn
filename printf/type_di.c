/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:51:59 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:52:01 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	helpme_11(t_buffer *b, t_flags *f, long num)
{
	if (num < 0 && f->b_zero_padding == 0)
		add_to_buffer(b, f, '-');
	while (f->zeros-- > 0)
	{
		if (f->neg_num == 1 && f->b_zero_padding == 1 && f->b_only_once == 0)
		{
			add_to_buffer(b, f, '-');
			f->b_only_once = 1;
		}
		add_to_buffer(b, f, '0');
	}
}

char	*type_di2(t_buffer *b, t_flags *f, long num, char *str)
{
	helpme_11(b, f, num);
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		if (f->width != 0)
			(b->buffer[b->buff_i] = ' ');
	else
		(b->buffer[b->buff_i] = '\0');
	else
	{
		if (f->neg_num == 1 && f->b_zero_padding == 1 && f->b_only_once == 0)
			add_to_buffer(b, f, '-');
		ft_putnbr(b, f, num);
	}
	if (f->b_left_aligned)
	{
		while (f->negative-- - f->to_write >= 1 && \
			f->negative - f->precision - f->neg_num >= 0)
			add_to_buffer(b, f, ' ');
	}
	return (str);
}

void	helpme_12(t_flags *f, t_buffer *b, long num)
{
	if (num < 0)
		f->neg_num = 1;
	else
		f->neg_num = 0;
	if (num == 0)
		f->b_num_zero = 1;
	else
		f->b_num_zero = 0;
	if (f->neg_num == 0 && f->space == 1 \
		 && f->countspace-- != 0)
		add_to_buffer(b, f, ' ');
	if (f->neg_num == 0 && f->plus == 1 && f->count_plus-- != 0)
		add_to_buffer(b, f, '+');
	if ((ft_putnbr_len(f, num) - f->neg_num) >= 1)
		f->to_write = ft_putnbr_len(f, num);
	else
		f->to_write = f->neg_num;
}

char	*type_di1(t_buffer *b, t_flags *f, long num, char *str)
{
	helpme_12(f, b, num);
	if ((f->b_left_aligned == 1 && f->b_zero_padding == 1) || (num == 0))
		f->b_zero_padding = 0;
	if ((f->b_preci == 1 || f->b_preci == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write + f->neg_num;
	else if (f->b_preci == 2 && f->precision == 0 && num == 0)
		f->to_write = 0;
	if (!f->b_left_aligned)
		f->width = f->width - f->to_write - f->zeros;
	if (f->b_zero_padding == 1 && !f->b_left_aligned && f->b_preci == 0)
	{
		if (f->neg_num == 1 && f->b_zero_padding == 1 && f->b_only_once == 0)
		{
			b->buffer[b->buff_i++] = '-';
			f->b_only_once = 1;
		}
		while (f->width > 0)
			add_to_buffer(b, f, '0');
	}
	else if (!f->b_left_aligned)
		while (f->width >= 1)
			add_to_buffer(b, f, ' ');
	return (type_di2(b, f, num, str));
}
