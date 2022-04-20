/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <gaderric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:17:52 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/13 18:52:38 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = ft_strlen(dest);
	b = ft_strlen(src);
	if (dstsize <= a)
		return (dstsize + b);
	while (src[i] && a + i + 1 < dstsize)
	{
		dest[a + i] = src[i];
		i++;
	}
	dest[a + i] = 0;
	return (a + b);
}
