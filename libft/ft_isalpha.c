/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:13:50 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/09 16:23:38 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	start_up;
	int	end_up;
	int	start_low;
	int	end_low;

	start_up = 65;
	end_up = 90;
	start_low = 97;
	end_low = 122;
	if ((c >= start_up && c <= end_up) \
			|| (c >= start_low && c <= end_low))
		return (1);
	else
		return (0);
}
