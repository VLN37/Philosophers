/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:48:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 17:23:54 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	philo[0]->args->start = get_time();
	while (++i < max_philo)
	{
		philo[i]->last_meal = philo[0]->args->start;
		pthread_create(&threads[i], NULL, &cave, (void *)philo[i]);
	}
	i = -1;
	while (++i < max_philo)
		pthread_join(threads[i], NULL);
	usleep(10000);
	cleanup(philo, max_philo);
	free(threads);
	return (0);
}
