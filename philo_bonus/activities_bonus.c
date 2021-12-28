/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:14:19 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 03:31:14 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	grab_forks(t_philo *philo)
{
	if (sem_wait(philo->sem->named) == -1)
		printf("sem error\n");
	sem_wait(&philo->sem->msg);
	if (philo->args->simulation_done == false)
	{
		print_msg(philo, "has grabbed fork1");
	}
	else
		sem_post(&philo->sem->msg);
	sem_wait(philo->sem->named);
	sem_wait(&philo->sem->msg);
	if (philo->args->simulation_done == false)
		print_msg(philo, "has grabbed fork2");
	else
		sem_post(&philo->sem->msg);
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->sem->named);
	sem_post(philo->sem->named);
}

t_bool	eat(t_philo *philo)
{
	grab_forks(philo);
	if (!philo->dead && philo->meals < philo->args->max_meals
		&& philo->args->simulation_done == false)
	{
		philo->last_meal = print_msg(philo, "is eating");
		usleep(philo->args->time_to_eat * 1000);
		drop_forks(philo);
		philo->meals++;
	}
	else
		drop_forks(philo);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	if (philo->args->meals_arg && philo->meals >= philo->args->max_meals)
		return (false);
	return (true);
}

t_bool	sleeping(t_philo *philo)
{
	sem_wait(&philo->sem->msg);
	if (!philo->dead)
	{
		print_msg(philo, "is sleeping");
		usleep(philo->args->time_to_sleep * 1000);
	}
	else
		sem_post(&philo->sem->msg);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}

t_bool	think(t_philo *philo)
{
	sem_wait(&philo->sem->msg);
	if (!philo->dead)
		print_msg(philo, "is thinking");
	else
		sem_post(&philo->sem->msg);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}
