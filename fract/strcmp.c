/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:25:23 by qabderus          #+#    #+#             */
/*   Updated: 2021/12/09 12:35:11 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				j;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	j = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((a[i] || b[i]))
	{
		if (a[i] != b[i])
		{
			j = a[i] - b[i];
			return (j);
		}
		else
			i++;
	}
	return (0);
}
