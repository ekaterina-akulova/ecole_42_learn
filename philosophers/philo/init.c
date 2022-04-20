/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:43:58 by gaderric          #+#    #+#             */
/*   Updated: 2022/04/02 15:44:00 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_settings	*init_settings(int argc, const char **argv)
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (0);
	settings->start_time = get_time();
	settings->num_of_phil = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		settings->should_eat = ft_atoi(argv[5]);
	else
		settings->should_eat = -2;
	if (settings->num_of_phil <= 0 || settings->time_to_die <= 0
		|| settings->time_to_eat <= 0 || settings->time_to_sleep <= 0
		|| settings->should_eat == -1 || settings->should_eat == 0)
	{
		free(settings);
		return (0);
	}
	return (settings);
}

int	create_threads(t_settings *settings)
{
	int	i;

	i = 0;
	settings->threads = malloc(sizeof(pthread_t) * settings->num_of_phil);
	if (!settings->threads)
		return (0);
	while (i < settings->num_of_phil)
	{
		if (pthread_create(&settings->threads[i], NULL,
				behavior, (void *)settings->philos[i]))
			return (0);
		pthread_detach(settings->threads[i]);
		i++;
	}
	return (1);
}

t_philosopher	*create_phil(t_settings *settings, int i)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!phil)
		return (NULL);
	phil->name = name_gen(phil->name);
	phil->start_time = settings->start_time;
	phil->index = i + 1;
	phil->l_fork = i;
	phil->r_fork = i + 1;
	if (i == settings->num_of_phil - 1)
		phil->r_fork = 0;
	phil->last_eaten = settings->start_time;
	phil->time_to_eat = settings->time_to_eat;
	phil->time_to_sleep = settings->time_to_sleep;
	phil->should_eat = settings->should_eat;
	phil->forks = settings->forks;
	phil->saying = &settings->saying;
	phil->eating = 0;
	return (phil);
}

int	generate_philos(t_settings *settings)
{
	int	i;

	settings->philos = malloc(sizeof(t_philosopher *) * settings->num_of_phil);
	settings->forks = malloc(sizeof(pthread_mutex_t) * settings->num_of_phil);
	if (!settings->philos || !settings->forks)
		return (0);
	i = 0;
	pthread_mutex_init(&settings->saying, NULL);
	while (i < settings->num_of_phil)
	{
		pthread_mutex_init(&settings->forks[i], NULL);
		settings->philos[i] = create_phil(settings, i);
		if (!settings->philos[i])
			return (0);
		i++;
	}
	return (1);
}

void	destroy_philos_without_free(t_settings	*settings)
{
	int	i;

	i = 0;
	while (i < settings->num_of_phil)
	{
		pthread_mutex_destroy(&settings->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&settings->saying);
	free(settings->philos);
	free(settings->forks);
	free(settings->threads);
}
