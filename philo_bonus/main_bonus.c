/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:05:16 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/23 12:00:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		**philo;

	sem_unlink("farol");
	sem_unlink("msg");
	sem_unlink("table");
	sem_unlink("finish");
	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	philo = init(philo, argc, argv);
	spawn_processes(philo);
	wait_patiently(philo);
	usleep(2000);
	kill_threads(philo);
	usleep(2000);
	cleanup(philo, philo[0]->args->max_philo, philo[0]->args->pids);
	return (EXIT_SUCCESS);
}
