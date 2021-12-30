/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:14:23 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 17:38:07 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		**philo;
	int			i;

	sem_unlink("farol");
	sem_unlink("msg");
	sem_unlink("table");
	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	philo = init(philo, argc, argv);
	i = -1;
	philo[0]->args->pids = malloc(sizeof(int) * philo[0]->args->max_philo);
	philo[0]->args->start = get_time();
	while (++i < philo[0]->args->max_philo)
	{
		philo[i]->last_meal = philo[0]->args->start;
		philo[0]->args->pids[i] = fork();
		if (philo[0]->args->pids[i] == 0)
			cave((void *)philo[i]);
	}
	waitpid(-1, NULL, 0);
	usleep(5000);
	i = -1;
	while (++i < philo[0]->args->max_philo)
		kill(philo[0]->args->pids[i], SIGKILL);
	usleep(5000);
	cleanup(philo, philo[0]->args->max_philo, philo[0]->args->pids);
	return (EXIT_SUCCESS);
}
