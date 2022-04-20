/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:17:10 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/13 20:39:26 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (((unsigned char) c) == *s)
		{
			return ((char *) s);
		}
		s++;
	}
	if (c == 0)
	{
		return ((char *) s);
	}
	return (NULL);
}
