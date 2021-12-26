/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:48:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 00:18:47 by jofelipe         ###   ########.fr       */
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

void	cleanup(t_philo *philo)
{
	free(philo->args);
	free(philo);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	t_philo		*philo;
	// t_philo		**philo;
	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	// philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	philo = malloc(sizeof(t_philo));
	init(philo, argc, argv);
	philo->args->start = get_time();
	pthread_create(&t1, NULL, &cave, (void *)philo);
	pthread_join(t1, NULL);
	cleanup(philo);
	return (0);
}
