/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:33:27 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/13 22:59:48 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s + 1);
	if (s != NULL)
	{
		if (len && *s && fd)
		{
			while (s[i] && i <= len)
			{
				write(fd, &s[i], 1);
				i++;
			}
		}
	}
}
