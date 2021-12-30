/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:58:41 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 03:39:43 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*cave(void *content)
{
	t_philo		*philo;
	pthread_t	reaper;

	philo = (t_philo *)content;
	if (philo->id % 2)
		usleep(5000);
	philo->sem->named = sem_open("farol", 0);
	philo->sem->msgs = sem_open("msg", 0);
	philo->sem->table = sem_open("table", 0);
	pthread_create(&reaper, NULL, &watch, content);
	pthread_detach(reaper);
	while (eat(philo) && sleeping(philo) && think(philo))
		continue ;
	usleep(5000);
	cleanup_child((t_philo **)philo->ptr, philo, philo->args->max_philo, philo->args->pids);
	exit(EXIT_SUCCESS);
}
