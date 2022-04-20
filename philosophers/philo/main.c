/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:12:42 by gaderric          #+#    #+#             */
/*   Updated: 2022/04/02 16:12:44 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup_forks(t_philosopher *phil)
{
	if (phil->index % 2 == 1)
	{
		pthread_mutex_lock(&(phil->forks[phil->r_fork]));
		say("%d %d %s has taken a fork\n", phil, phil->name);
		pthread_mutex_lock(&(phil->forks[phil->l_fork]));
		say("%d %d %s has taken a fork\n", phil, phil->name);
	}
	else
	{
		pthread_mutex_lock(&(phil->forks[phil->l_fork]));
		say("%d %d %s has taken a fork\n", phil, phil->name);
		pthread_mutex_lock(&(phil->forks[phil->r_fork]));
		say("%d %d %s has taken a fork\n", phil, phil->name);
	}
}

void	*behavior(void *philosoph)
{
	t_philosopher	*philo;

	philo = philosoph;
	while (philo->should_eat != 0)
	{
		pickup_forks(philo);
		philo->eating = 1;
		say("%d %d %s is eating\n", philo, philo->name);
		philo->last_eaten = get_time();
		thread_sleep(philo->time_to_eat);
		pthread_mutex_unlock(&(philo->forks[philo->l_fork]));
		pthread_mutex_unlock(&(philo->forks[philo->r_fork]));
		philo->eating = 0;
		say("%d %d %s is sleeping\n", philo, philo->name);
		thread_sleep(philo->time_to_sleep);
		say("%d %d %s is thinking\n", philo, philo->name);
		philo->should_eat--;
	}
	return (0);
}

int	say_philo_dead(t_philosopher *philo)
{
	pthread_mutex_lock(philo->saying);
	printf("%d %d died\n", timestamp(philo), philo->index);
	return (0);
}

int	check_philos(t_settings *settings)
{
	int	i;
	int	checked_all;

	while (1)
	{
		i = -1;
		checked_all = 0;
		while (++i < settings->num_of_phil)
		{
			if (settings->philos[i]->should_eat == 0)
				continue ;
			checked_all = 1;
			if (settings->philos[i]->eating == 1)
				continue ;
			if (settings->time_to_die < get_time()
				- settings->philos[i]->last_eaten)
				return (say_philo_dead(settings->philos[i]));
		}
		if (checked_all == 0)
			return (1);
		usleep(1000);
	}
}

int	main(int argc, char const *argv[])
{
	t_settings	*settings;

	if (argc < 5 || argc > 6)
		return (0);
	settings = init_settings(argc, argv);
	if (!settings || !generate_philos(settings) || !create_threads(settings))
		return (0);
	if (check_philos(settings))
		destroy_philos(settings);
	else
		destroy_philos_without_free(settings);
	free(settings);
	return (1);
}
