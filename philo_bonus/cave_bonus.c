/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:58:41 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/22 09:47:50 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*cave(void *content)
{
	t_philo		*philo;
	pthread_t	the_devil;

	philo = (t_philo *)content;
	if (philo->id % 2)
		usleep(5000);
	philo->sem->forks = sem_open("farol", 0);
	philo->sem->msgs = sem_open("msg", 0);
	philo->sem->table = sem_open("table", 0);
	philo->sem->signal = philo->sem->msgs;
	pthread_create(&the_devil, NULL, &see_you_in_hell, content);
	pthread_detach(the_devil);
	while (eat(philo) && _sleep(philo) && think(philo))
		continue ;
	usleep(10000);
	cleanup_child((t_philo **)philo->ptr, philo, philo->dead);
	exit(EXIT_SUCCESS);
}
