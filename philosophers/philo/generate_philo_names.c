/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo_names.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:43:41 by gaderric          #+#    #+#             */
/*   Updated: 2022/04/02 18:05:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 3/30/22.
//

#include "philo.h"

char	*ft_strscat(char *str1, const char *str2)
{
	while (*str1)
		str1++;
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (str1);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

char	*name_gen(char *player_name)
{
	char	name_prefix[][5] = {
			"",
			"bel",
			"nar",
			"xan",
			"bell",
			"natr",
			"ev",
	};

	char	name_suffix[][5] = {
			"", "us", "ix", "ox", "ith",
			"ath", "um", "ator", "or", "axia",
			"imus", "ais", "itur", "orex", "o",
			"y"
	};

	 char	name_stems[][10] = {
			"adur", "aes", "anim", "apoll", "imac",
			"educ", "equis", "extr", "guius", "hann",
			"equi", "amora", "hum", "iace", "ille",
			"inept", "iuv", "obe", "ocul", "orbis"
	};

	player_name = malloc(sizeof(char *));
	player_name[0] = 0;
	ft_strscat(player_name, name_prefix[(rand() % 7)]);
	ft_strscat(player_name, name_stems[(rand() % 20)]);
	ft_strscat(player_name, name_suffix[(rand() % 16)]);
	player_name[0] = ft_toupper(player_name[0]);
	return (player_name);
}