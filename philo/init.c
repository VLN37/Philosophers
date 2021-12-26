/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:17:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 19:29:20 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	args->argc = argc;
	pthread_mutex_init(&args->waitereven, NULL);
	pthread_mutex_init(&args->waiterodd, NULL);
	args->simulation_done = false;
	args->max_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	return (args);
}

t_philo	*init_philo(char **argv, t_args *args, t_philo *philo, int i)
{
	philo = malloc(sizeof(t_philo));
	philo->id = i;
	philo->meals = 0;
	philo->fork1 = &args->forks[i];
	if (i == args->max_philo - 1)
		philo->fork2 = &args->forks[0];
	else
		philo->fork2 = &args->forks[i + 1];
	philo->dead = false;
	philo->args = args;
	if (args->argc == 6)
	{
		philo->args->meals_arg = true;
		philo->args->max_meals = ft_atoi(argv[5]);
	}
	else
	{
		philo->args->meals_arg = false;
		philo->args->max_meals = 2147483647;
	}
	return (philo);
}

void	init(t_philo **philo, int argc, char **argv)
{
	t_args			*args;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	*forks;
	int				i;

	pthread_mutex_init(&msg_mutex, NULL);
	args = init_args(argc, argv);
	forks = malloc(sizeof(pthread_mutex_t) * args->max_philo);
	args->forks = forks;
	i = -1;
	while (++i < args->max_philo)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < args->max_philo)
	{
		philo[i] = init_philo(argv, args, philo[i], i);
		philo[i]->msg = msg_mutex;
	}
}
