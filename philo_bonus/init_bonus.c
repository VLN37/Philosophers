/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:28:32 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/31 01:20:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_args	*init_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	args->argc = argc;
	args->simulation_done = false;
	args->max_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->pids = malloc(sizeof(int) * args->max_philo);
	return (args);
}

t_philo	*init_philo(char **argv, t_args *args, t_philo *philo, int i)
{
	philo = malloc(sizeof(t_philo));
	philo->id = i + 1;
	philo->meals = 0;
	philo->dead = false;
	philo->args = args;
	if (args->argc == 6)
	{
		philo->args->meals_arg = true;
		philo->args->max_meals = ft_atoi(argv[5]);
	}
	else
	{
		philo->args->meals_arg = false;
		philo->args->max_meals = 2147483647;
	}
	return (philo);
}

void	init_sem(t_sem *sem, char **argv)
{
	sem->forks = sem_open("farol", O_CREAT, 0777, ft_atoi(argv[1]));
	sem->msgs = sem_open("msg", O_CREAT, 0777, 1);
	sem->table = sem_open("table", O_CREAT, 0777, ft_atoi(argv[1]) - 2);
}

t_philo	**init(t_philo **philo, int argc, char **argv)
{
	t_args			*args;
	t_sem			*sem;
	int				i;

	sem = malloc(sizeof(t_sem));
	init_sem(sem, argv);
	args = init_args(argc, argv);
	i = -1;
	while (++i < args->max_philo)
	{
		philo[i] = init_philo(argv, args, philo[i], i);
		philo[i]->sem = sem;
	}
	return (philo);
}
