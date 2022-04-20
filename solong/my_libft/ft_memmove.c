/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:16:28 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:16:30 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*ptr1;

	ptr = (char *) dst;
	ptr1 = (char *) src;
	if (src > dst)
	{
		while ((len--) && ((src != (NULL)) || (dst != (NULL))))
		{
			*ptr++ = *ptr1++;
		}
	}
	if (src < dst)
	{
		while ((len--) && ((src != (NULL)) || (dst != (NULL))))
		{
			ptr[len] = ptr1[len];
		}
	}
	return ((void *)(dst));
}
