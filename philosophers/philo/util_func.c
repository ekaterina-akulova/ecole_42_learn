/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:44:29 by gaderric          #+#    #+#             */
/*   Updated: 2022/04/02 15:48:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	timestamp(t_philosopher *philo)
{
	return ((int)(get_time() - philo->start_time));
}

void	thread_sleep(unsigned long time)
{
	unsigned long	now;
	unsigned long	until;

	now = get_time();
	until = now + time;
	while (until > now)
	{
		now = get_time();
		if (now >= until)
			return ;
		usleep(20);
	}
}

void	say(char *str, t_philosopher *philo, char *name)
{
	pthread_mutex_lock(philo->saying);
	printf(str, timestamp(philo), philo->index, name);
	pthread_mutex_unlock(philo->saying);
}

void	destroy_philos(t_settings	*settings)
{
	int	i;

	i = 0;
	while (i < settings->num_of_phil)
	{
		pthread_mutex_destroy(&settings->forks[i]);
		free(settings->philos[i]);
		i++;
	}
	pthread_mutex_destroy(&settings->saying);
	free(settings->philos);
	free(settings->forks);
	free(settings->threads);
}
