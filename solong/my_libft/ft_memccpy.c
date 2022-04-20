/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:15:19 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:15:23 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;

	c = (unsigned char) c;
	ptr = (unsigned char *) dst;
	ptr1 = (unsigned char *) src;
	while ((n--) && ((src != (NULL)) || (dst != (NULL))))
	{
		if (*ptr1 == c)
		{
			*ptr++ = *ptr1++;
			return ((void *)ptr);
			break ;
		}
		*ptr++ = *ptr1++;
	}
	return (NULL);
}
