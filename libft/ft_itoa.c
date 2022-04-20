/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:03:51 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/13 23:30:10 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(long int c)
{
	if (c < 10)
		return (1);
	else
	{
		return (ft_nbrlen(c / 10) + 1);
	}
}

static void	ft_f(long int n, char *str, int count)
{
	while (count > 0)
	{
		str[count - 1] = (n % 10) + '0';
		count--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int			a;
	char		*str;
	char		*str1;
	int			size;
	long int	ln;

	a = 0;
	ln = n;
	if (ln < 0)
	{
		a = 1;
		ln = -ln;
	}
	size = ft_nbrlen(ln);
	str = ft_calloc(1 + size + a, sizeof(char));
	if (!str)
		return (NULL);
	str1 = str;
	if (a)
		*str = '-';
	ft_f(ln, str + a, size);
	str[size + a] = '\0';
	return (str1);
}
