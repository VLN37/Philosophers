/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:17:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 01:10:11 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_args(char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	args->max_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	return (args);
}

void	init(t_philo **philo, int argc, char **argv)
{
	t_args			*args;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	*forks;
	int				i;

	pthread_mutex_init(&msg_mutex, NULL);
	args = init_args(argv);
	forks = malloc(sizeof(pthread_mutex_t) * args->max_philo);
	args->forks = forks;
	i = -1;
	while (++i < args->max_philo)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < args->max_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = i;
		philo[i]->meals = 0;
		philo[i]->fork1 = forks[i];
		if (i == args->max_philo)
			philo[i]->fork2 = forks[0];
		else
			philo[i]->fork2 = forks[i];
		philo[i]->dead = false;
		philo[i]->args = args;
		philo[i]->msg = msg_mutex;
		if (argc == 6)
		{
			philo[i]->args->meals_arg = true;
			philo[i]->args->max_meals = ft_atoi(argv[5]);
		}
		else
			philo[i]->args->meals_arg = false;
	}
}
