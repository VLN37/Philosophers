/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:48:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 00:47:45 by jofelipe         ###   ########.fr       */
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

void	cleanup(t_philo **philo, int max_philo)
{
	int	i;

	i = -1;
	free(philo[0]->args);
	while (++i < max_philo)
		free(philo[i]);
	free(philo);
}

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_philo		**philo;
	int			max_philo;
	int			i;

	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	max_philo = ft_atoi(argv[1]);
	threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	init(philo, argc, argv);
	i = -1;
	while (++i < max_philo)
	{
		philo[i]->args->start = get_time();
		pthread_create(&threads[i], NULL, &cave, (void *)philo[i]);
	}
	i = -1;
	while (++i < max_philo)
		pthread_join(threads[i], NULL);
	cleanup(philo, max_philo);
	free(threads);
	return (0);
}
