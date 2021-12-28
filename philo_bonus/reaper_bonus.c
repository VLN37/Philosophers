/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:30:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 05:29:33 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
			sem_wait(philo->sem->msgs);
			philo->dead = true;
			philo->args->simulation_done = true;
			time = get_time() - start;
			printf("%-5lld philo #%d is dead\n", time, philo->id);
			sem_post(philo->sem->msgs);
			sem_close(philo->sem->named);
			return (NULL);
		}
		usleep(10);
		if (philo->meals >= philo->args->max_meals
			|| philo->args->simulation_done)
			return (NULL);
	}
}
