/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:45:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 06:54:20 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(&philo->args->msg);
	if (philo->args->simulation_done == false)
		print_msg(philo, "has grabbed fork1");
	else
		pthread_mutex_unlock(&philo->args->msg);
	if (philo->args->max_philo == 1)
	{
		usleep(philo->args->time_to_die * 1001);
		return ;
	}
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(&philo->args->msg);
	if (philo->args->simulation_done == false)
		print_msg(philo, "has grabbed fork2");
	else
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
	pthread_mutex_lock(&philo->args->msg);
	if (!philo->dead)
	{
		print_msg(philo, "is sleeping");
		usleep(philo->args->time_to_sleep * 1000);
	}
	else
		pthread_mutex_unlock(&philo->args->msg);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}

t_bool	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->msg);
	if (!philo->dead)
		print_msg(philo, "is thinking");
	else
		pthread_mutex_unlock(&philo->args->msg);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}
