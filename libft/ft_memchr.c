/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <gaderric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:15:43 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/13 20:32:38 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;

	if (n == 0)
		return (NULL);
	a = (unsigned char *) s;
	while (n > 0)
	{
		if (*a == (unsigned char)c)
		{
			return ((void *) a);
		}
		a++;
		n--;
	}
	return (NULL);
}
