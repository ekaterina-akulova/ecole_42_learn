/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:15:58 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:16:01 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a1;
	char	*a2;

	a1 = (char *) s1;
	a2 = (char *) s2;
	while (n && (*a1 == *a2))
	{
		++a1;
		++a2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)a1 - *(unsigned char *)a2);
	}
}
