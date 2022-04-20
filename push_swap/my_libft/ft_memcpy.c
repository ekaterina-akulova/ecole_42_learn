/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:16:09 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:16:11 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;
	char	*ptr1;

	ptr = (char *) dst;
	ptr1 = (char *) src;
	while ((n--) && ((src != (NULL)) || (dst != (NULL))))
	{
		*ptr++ = *ptr1++;
	}
	return ((void *)(dst));
}
