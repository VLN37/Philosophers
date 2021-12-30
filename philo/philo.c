/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:48:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 11:54:41 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spawn_threads(t_philo **philo, pthread_t *threads)
{
	int	i;

	i = -1;
	philo[0]->args->start = get_time();
	while (++i < philo[0]->args->max_philo)
	{
		philo[i]->last_meal = philo[0]->args->start;
		pthread_create(&threads[i], NULL, &cave, (void *)philo[i]);
	}
}

void	join_threads(t_philo **philo, pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < philo[0]->args->max_philo)
		pthread_join(threads[i], NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_philo		**philo;

	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	init(philo, argc, argv);
	spawn_threads(philo, threads);
	join_threads(philo, threads);
	usleep(5000);
	cleanup(philo);
	free(threads);
	return (0);
}
