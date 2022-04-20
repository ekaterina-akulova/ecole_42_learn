/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:17:38 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:17:41 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	size_t	ch;
	char	*ch2;
	int		i;

	i = 0;
	ch = ft_strlen(str);
	ch2 = malloc((sizeof(char)) * (ch + 1));
	if (!ch2)
		return (NULL);
	while (*str)
	{
		ch2[i] = *str;
		i++;
		str++;
	}
	ch2[i] = '\0';
	return (ch2);
}
