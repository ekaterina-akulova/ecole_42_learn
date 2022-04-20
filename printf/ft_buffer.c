/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:49:16 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:49:19 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_and_clear(t_buffer *b)
{
	b->written += b->buff_i;
	write(1, b->buffer, BUFFER_SIZE);
	ft_bzero(b->buffer, sizeof(b->buffer));
	b->buff_i = 0;
}

void	add_to_buffer(t_buffer *b, t_flags *f, char c)
{
	if (b->buff_i == BUFFER_SIZE)
		write_and_clear(b);
	b->buffer[b->buff_i] = c;
	b->buff_i++;
	f->width--;
}
