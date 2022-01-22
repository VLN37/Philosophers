/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 02:58:08 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/22 10:00:06 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_child(t_philo **philo, t_philo *me, int exit_code)
{
	int	i;
	int	max_philo;

	max_philo = me->args->max_philo;
	i = -1;
	free(me->args->pids);
	sem_close(me->sem->msgs);
	sem_close(me->sem->forks);
	sem_close(me->sem->table);
	sem_close(me->sem->signal);
	sem_close(philo[0]->sem->msgs);
	sem_close(philo[0]->sem->forks);
	sem_close(philo[0]->sem->table);
	sem_close(philo[0]->sem->signal);
	free(philo[0]->args);
	free(philo[0]->sem);
	while (++i < max_philo)
		free(philo[i]);
	free(philo);
	exit(exit_code);
}

void	cleanup(t_philo **philo, int max_philo, int *pid)
{
	int	i;

	i = -1;
	free(pid);
	free(philo[0]->args);
	sem_close(philo[0]->sem->msgs);
	sem_close(philo[0]->sem->forks);
	sem_close(philo[0]->sem->table);
	sem_close(philo[0]->sem->signal);
	free(philo[0]->sem);
	while (++i < max_philo)
		free(philo[i]);
	free(philo);
	sem_unlink("farol");
	sem_unlink("msg");
	sem_unlink("table");
}
