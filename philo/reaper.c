/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:31:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 19:33:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watch(void *arg)
{
	t_philo			*philo;
	long long int	time;
	long long int	start;

	philo = (t_philo *)arg;
	start = philo->args->start;
	while (1)
	{
		time = get_time() - start - philo->last_meal;
		if (time > philo->args->time_to_die && !philo->args->simulation_done)
		{
			philo->dead = true;
			philo->args->simulation_done = true;
			pthread_mutex_lock(&philo->msg);
			time = get_time() - start;
			printf("%-5lld philo #%d is dead\n", time, philo->id);
			pthread_mutex_unlock(&philo->msg);
			return (NULL);
		}
		if (philo->meals >= philo->args->max_meals)
			return (NULL);
		if (philo->args->simulation_done)
			return (NULL);
		usleep(100);
	}
}
