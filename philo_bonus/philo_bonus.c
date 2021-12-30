/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:14:23 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 11:10:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	spawn_processes(t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < philo[0]->args->max_philo)
		philo[i]->ptr = (void **)philo;
	i = -1;
	philo[0]->args->start = get_time();
	while (++i < philo[0]->args->max_philo)
	{
		philo[i]->last_meal = philo[0]->args->start;
		philo[0]->args->pids[i] = fork();
		if (philo[0]->args->pids[i] == 0)
			cave((void *)philo[i]);
	}
}

void	wait_patiently(t_philo **philo)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;
	while (!exit_code && i < philo[0]->args->max_philo)
	{
		waitpid(-1, &exit_code, 0);
		WEXITSTATUS(exit_code);
		i++;
	}
}

void	kill_threads(t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < philo[0]->args->max_philo)
		kill(philo[0]->args->pids[i], SIGKILL);
}
