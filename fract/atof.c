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

int	ft_start(const char *str, int *j)
{
	int	i;
	int	k;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		*j = *j * (-1);
		i++;
	}
	else if (str[i] == 43)
		i++;
	k = i;
	while (str[k])
	{
		if ((str[k] < 48 || str[k] > 57) && str[k] != 46)
		{
			printf("Please enter value only with numbers and '.', ok thanks");
			exit(1);
		}
		k++;
	}
	return (i);
}

void	exit_atof(void)
{
	printf("Please enter proper values for julia set");
	exit (1);
}

double	ft_double_count(const char *str, int i, double k)
{
	int		p;
	int		count;
	double	irr;

	if (str[i] == 46)
		i++;
	else
		exit_atof();
	p = 0;
	count = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		p++;
		irr = (str[i] - 48);
		while (count != p)
		{
			irr = irr / 10;
			count++;
		}
		count = 0;
		k = k + irr;
		i++;
	}
	return (k);
}

double	ft_atof(const char *str)
{
	int				i;
	int				j;
	double			k;

	k = 0;
	j = 1;
	i = ft_start(str, &j);
	if (str[i] > 47 && str[i] < 58)
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	k = ft_double_count(str, i, k);
	if (j > 0)
		return (k);
	return (-k);
}
