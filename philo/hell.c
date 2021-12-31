
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:31:42 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/31 03:18:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*see_you_in_hell(void *arg)
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
			pthread_mutex_lock(&philo->args->msg);
			philo->dead = true;
			philo->args->simulation_done = true;
			print_msg(philo, DIE);
			pthread_mutex_unlock(&philo->args->msg);
			return (NULL);
		}
		usleep(200);
		if (philo->meals >= philo->args->max_meals
			|| philo->args->simulation_done)
			return (NULL);
	}
}
