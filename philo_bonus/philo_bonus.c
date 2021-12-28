/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:14:23 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 02:45:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		**philo;
	int			max_philo;
	int			pid;
	int			i;

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
	sem_post(&philo[0]->sem->forks);
	waitpid(-1, NULL, 0);
}
