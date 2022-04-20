/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:45:16 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 23:45:17 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_p(t_buffer *b, t_flags *f, unsigned long int num, char *str)
{
	char	type;

	type = 'p';
	if (num == 0)
		f->b_num_zero = 1;
	else
		f->b_num_zero = 0;
	f->to_write = ft_puthexa_len(b, f, num);
	str = conversion_helper(b, f, str, 'p');
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && num == 0 && f->width != 0)
		(b->buffer[b->buff_i] = ' ');
	else if (f->b_preci != 2 && f->precision != 0 \
		 && num != 0 && f->width == 0)
		(b->buffer[b->buff_i] = '\0');
	else
		ft_puthexa(b, f, num, &type);
	if (f->b_left_aligned)
	{
		while ((f->negative-- - f->to_write) > 2)
			add_to_buffer(b, f, ' ');
	}
	return (str);
}
