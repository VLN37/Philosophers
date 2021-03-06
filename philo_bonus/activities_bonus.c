/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:14:19 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/23 13:24:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	grab_forks(t_philo *philo)
{
	sem_wait(philo->sem->forks);
	if (philo->dead)
		return ;
	else
		sem_wait(philo->sem->msgs);
	if (philo->args->simulation_done == false)
		print_msg(philo, PICK_FORK);
	sem_post(philo->sem->msgs);
	if (philo->args->max_philo == 1)
	{
		usleep(philo->args->time_to_die * 1001);
		return ;
	}
	sem_wait(philo->sem->forks);
	if (philo->dead)
		return ;
	else
		sem_wait(philo->sem->msgs);
	if (philo->args->simulation_done == false)
		print_msg(philo, PICK_FORK);
	sem_post(philo->sem->msgs);
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->sem->forks);
	sem_post(philo->sem->forks);
}

t_bool	eat(t_philo *philo)
{
	if (philo->args->max_philo > 2)
		sem_wait(philo->sem->table);
	grab_forks(philo);
	if (philo->dead)
		return (false);
	sem_wait(philo->sem->msgs);
	if (!philo->dead && philo->meals < philo->args->max_meals
		&& !philo->args->simulation_done)
	{
		philo->last_meal = print_msg(philo, EAT);
		sem_post(philo->sem->msgs);
		msleep(philo->args->time_to_eat);
		philo->meals++;
	}
	else
		sem_post(philo->sem->msgs);
	drop_forks(philo);
	if (philo->args->max_philo > 1)
		sem_post(philo->sem->table);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	if (philo->args->meals_arg && philo->meals >= philo->args->max_meals)
		return (false);
	return (true);
}

t_bool	_sleep(t_philo *philo)
{
	if (philo->dead)
		return (false);
	else
		sem_wait(philo->sem->msgs);
	if (!philo->dead && !philo->args->simulation_done)
		print_msg(philo, SLEEP);
	sem_post(philo->sem->msgs);
	msleep(philo->args->time_to_sleep);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}

t_bool	think(t_philo *philo)
{
	if (philo->dead)
		return (false);
	else
		sem_wait(philo->sem->msgs);
	if (!philo->dead && !philo->args->simulation_done)
		print_msg(philo, THINK);
	sem_post(philo->sem->msgs);
	usleep(50);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}
