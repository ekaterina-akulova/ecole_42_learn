/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <gaderric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:19:28 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/13 21:32:14 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if ((big[i] == little[0]) && \
			(ft_strncmp(big + i, little, little_len)) == 0 \
			&& (i + little_len <= len))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
