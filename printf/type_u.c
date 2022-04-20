/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:53:02 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:53:05 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_u(t_buffer *b, t_flags *f, unsigned int num, char *str)
{
	if (num == 0)
		f->b_num_zero = 1;
	else
		f->b_num_zero = 0;
	f->to_write = ft_putnbr_len(f, num);
	str = conversion_helper(b, f, str, 'u');
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
	{
		if (f->width != 0)
			(b->buffer[b->buff_i] = ' ');
		 else
			(b->buffer[b->buff_i] = '\0');
	}
	else
		ft_putnbr(b, f, num);
	if (f->b_left_aligned)
		while (f->negative-- - f->to_write >= 1 \
			&& f->negative - f->precision - f->neg_num >= 0)
			add_to_buffer(b, f, ' ');
	return (str);
}
