/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:16:51 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:25:24 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned char	sym;

	ptr = b;
	sym = (unsigned char)c;
	while (len--)
	{
		*ptr = sym;
		ptr++;
	}
	return (b);
}
