/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:07:06 by gaderric          #+#    #+#             */
/*   Updated: 2022/01/21 21:29:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 12/15/21.
//

#include "checker.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || \
	c == '\f' || c == '\v' || c == ' ')
	return (1);
	else
		return (0);
}

long	*ft_ialloc_2(size_t count, size_t size)
{
	long	*ch;
	size_t	i;

	i = 0;
	ch = malloc(size * count);
	if (!(ch))
		return (NULL);
	while (i < count)
		ch[i++] = AER;
	return (ch);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
