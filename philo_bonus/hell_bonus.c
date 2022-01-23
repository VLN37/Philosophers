/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:30:30 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/23 08:13:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	apocalypse(t_philo *philo)
{
	int	i;

	i = -1;
	philo->sem->msgs = (sem_t *)666;
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
		time = get_time() - start - philo->last_meal;
		if (time > philo->args->time_to_die && philo->sem->msgs != (sem_t *)666)
		{
			sem_wait(philo->sem->msgs);
			philo->dead = true;
			philo->args->simulation_done = true;
			print_msg(philo, DIE);
			apocalypse(philo);
			sem_post(philo->sem->msgs);
			return (NULL);
		}
		usleep(200);
		if (philo->sem->msgs == (sem_t *)666)
			philo->dead = true;
		if (philo->meals >= philo->args->max_meals || philo->dead)
			return (NULL);
	}
}
