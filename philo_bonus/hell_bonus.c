/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:30:30 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/23 13:41:00 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	apocalypse(t_philo *philo)
{
	int	i;

	philo->dead = true;
	philo->args->simulation_done = true;
	i = -1;
	while (++i < philo->args->max_philo - 1)
	{
		sem_post(philo->sem->table);
		sem_post(philo->sem->forks);
		sem_post(philo->sem->forks);
	}
}

void	*see_you_in_hell(void *arg)
{
	t_philo			*philo;
	long long int	time;
	long long int	start;

	philo = (t_philo *)arg;
	start = philo->args->start;
	while (1)
	{
		if (philo->sem->finish->__align == 0)
			philo->args->simulation_done = true;
		time = get_time() - start - philo->last_meal;
		if (time > philo->args->time_to_die && philo->sem->finish->__align == 1)
		{
			sem_wait(philo->sem->msgs);
			print_msg(philo, DIE);
			sem_wait(philo->sem->finish);
			apocalypse(philo);
			return (NULL);
		}
		usleep(200);
		if (philo->meals >= philo->args->max_meals || philo->dead
			|| philo->args->simulation_done)
			return (NULL);
	}
}
