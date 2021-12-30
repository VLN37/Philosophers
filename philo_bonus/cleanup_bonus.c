/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 02:58:08 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 03:45:52 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_child(t_philo **philo, t_philo *me, int max_philo, int *pid)
{
	int	i;

	i = -1;
	free(pid);
	sem_close(me->sem->msgs);
	sem_close(me->sem->msgs);
	sem_close(me->sem->named);
	sem_close(me->sem->table);
	sem_close(philo[0]->sem->msgs);
	sem_close(philo[0]->sem->named);
	sem_close(philo[0]->sem->table);
	free(philo[0]->args);
	free(philo[0]->sem);
	while (++i < max_philo)
		free(philo[i]);
	free(philo);
}

void	cleanup(t_philo **philo, int max_philo, int *pid)
{
	int	i;

	i = -1;
	free(pid);
	free(philo[0]->args);
	sem_close(philo[0]->sem->msgs);
	sem_close(philo[0]->sem->named);
	sem_close(philo[0]->sem->table);
	free(philo[0]->sem);
	while (++i < max_philo)
		free(philo[i]);
	free(philo);
	sem_unlink("farol");
	sem_unlink("msg");
	sem_unlink("table");
}
