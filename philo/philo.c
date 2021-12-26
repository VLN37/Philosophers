/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:48:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/25 23:49:29 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *content)
{
	printf("hello\n");
	return (content);
}

t_bool	validation(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
	{
		printf("usage: ./philo num_of_philo time_to_die time_to_eat "
			"time_to_sleep (optional)times_to_eat\n");
		return (false);
	}
	return (true);
}

void	init(t_philo *philo, int argc, char **argv)
{
	philo->args = malloc(sizeof(t_args));
	philo->args->start = get_time();
	philo->meals = 0;
	philo->args->time_to_die = atoi(argv[2]);
	philo->args->time_to_eat = atoi(argv[3]);
	philo->args->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
	{
		philo->args->meals_arg = true;
		philo->args->max_meals = atoi(argv[5]);
	}
	else
		philo->args->meals_arg = false;
}

void	cleanup(t_philo *philo)
{
	free(philo->args);
	free(philo);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	t_philo		*philo;

	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo));
	init(philo, argc, argv);
	philo->args->start = get_time();
	pthread_create(&t1, NULL, &cave, (void *)philo);
	pthread_join(t1, NULL);
	cleanup(philo);
	return (0);
}
