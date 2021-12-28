/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:14:23 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 03:22:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		**philo;
	int			max_philo;
	int			pid;
	int			i;

	sem_unlink("farol");
	if (!validation(argc, argv))
		return (EXIT_FAILURE);
	max_philo = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	philo = init(philo, argc, argv);
	i = -1;
	philo[0]->args->start = get_time();
	while (++i < max_philo)
	{
		philo[i]->last_meal = 0;
		pid = fork();
		if (pid == 0)
			cave((void *)philo[i]);
	}
	sem_unlink("farol");
	waitpid(-1, NULL, 0);
}
