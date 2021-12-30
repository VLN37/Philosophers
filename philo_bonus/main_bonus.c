/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:05:16 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 11:20:49 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		**philo;

	sem_unlink("farol");
	sem_unlink("msg");
	sem_unlink("table");
	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	philo = init(philo, argc, argv);
	spawn_processes(philo);
	wait_patiently(philo);
	usleep(5000);
	kill_threads(philo);
	usleep(5000);
	cleanup(philo, philo[0]->args->max_philo, philo[0]->args->pids);
	return (EXIT_SUCCESS);
}
