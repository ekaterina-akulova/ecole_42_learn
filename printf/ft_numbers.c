/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:49:29 by gaderric          #+#    #+#             */
/*   Updated: 2021/11/12 22:49:34 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(t_buffer *b, t_flags *f, long n)
{
	if (n < 0)
		n = -n;
	if (n / 10)
		ft_putnbr(b, f, n / 10);
	add_to_buffer(b, f, n % 10 + '0');
}

long	ft_putnbr_len(t_flags *f, long i)
{
	size_t	len;
	long	next;

	if (i < 0)
	{
		i = -i;
		len = 2;
	}
	else
		len = 1;
	i /= 10;
	if (i != 0)
	{
		next = ft_putnbr_len(f, i);
		len += next;
	}
	f->num_len = len;
	return (f->num_len);
}

void	ft_puthexa(t_buffer *b, t_flags *f, unsigned long x, char *type)
{
	if (x >= 16)
		ft_puthexa(b, f, x / 16, type);
	if ((*type == 'p' && f->b_only_once == 0) || \
	(*type == 'x' && f->hash-- > 0 && x != 0))
	{
		add_to_buffer(b, f, '0');
		add_to_buffer(b, f, 'x');
		f->b_only_once = 1;
	}
	if ((*type == 'X' && f->hash-- > 0 && x != 0))
	{
		add_to_buffer(b, f, '0');
		add_to_buffer(b, f, 'X');
		f->b_only_once = 1;
	}
	if (*type == 'x' || *type == 'p')
		add_to_buffer(b, f, "0123456789abcdef"[x & 15]);
	else
		add_to_buffer(b, f, "0123456789ABCDEF"[x & 15]);
}

long	ft_puthexa_len(t_buffer *b, t_flags *f, unsigned long x)
{
	if (x >= 16)
	{
		f->num_len++;
		ft_puthexa_len(b, f, x / 16);
	}
	return (f->num_len + 1);
}
