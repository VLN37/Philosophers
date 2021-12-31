/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:45:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 23:56:13 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(&philo->args->msg);
	if (philo->args->simulation_done == false)
		print_msg(philo, PICK_FORK);
	pthread_mutex_unlock(&philo->args->msg);
	if (philo->args->max_philo == 1)
	{
		usleep(philo->args->time_to_die * 1001);
		return ;
	}
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(&philo->args->msg);
	if (philo->args->simulation_done == false)
		print_msg(philo, PICK_FORK);
	pthread_mutex_unlock(&philo->args->msg);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

t_bool	eat(t_philo *philo)
{
	grab_forks(philo);
	if (!philo->dead && philo->meals < philo->args->max_meals
		&& philo->args->simulation_done == false)
	{
		pthread_mutex_lock(&philo->args->msg);
		philo->last_meal = print_msg(philo, EAT);
		pthread_mutex_unlock(&philo->args->msg);
		msleep(philo->args->time_to_eat);
		philo->meals++;
	}
	drop_forks(philo);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	if (philo->args->meals_arg && philo->meals >= philo->args->max_meals)
		return (false);
	return (true);
}

t_bool	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->msg);
	if (!philo->args->simulation_done)
	{
		print_msg(philo, SLEEP);
		pthread_mutex_unlock(&philo->args->msg);
		msleep(philo->args->time_to_sleep);
	}
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}

t_bool	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->msg);
	if (!philo->args->simulation_done)
		print_msg(philo, THINK);
	pthread_mutex_unlock(&philo->args->msg);
	usleep(200);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}
