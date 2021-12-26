/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:17:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 00:18:17 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_args(char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	return (args);
}

void	init(t_philo *philo, int argc, char **argv)
{
	t_args	*args;

	args = init_args(argv);
	philo->meals = 0;
	philo->id = 0;
	philo->dead = false;
	philo->args = args;
	pthread_mutex_init(&philo->msg, NULL);
	if (argc == 6)
	{
		philo->args->meals_arg = true;
		philo->args->max_meals = ft_atoi(argv[5]);
	}
	else
		philo->args->meals_arg = false;
}
