/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:11:41 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:12:58 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ch;

	ch = malloc(size * count);
	if (!(ch))
		return (NULL);
	else
		ft_memset(ch, 0, count * size);
	return (ch);
}
