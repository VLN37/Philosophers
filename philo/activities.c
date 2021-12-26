/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:45:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 19:05:33 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(&philo->msg);
	if (philo->args->simulation_done == false)
	{
		philo->last_meal = get_time() - philo->args->start;
		printf("%-5lld philo #%d "
			"has grabbed fork1\n", philo->last_meal, philo->id);
		pthread_mutex_unlock(&philo->msg);
	}
	else
		pthread_mutex_unlock(&philo->msg);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(&philo->msg);
	if (philo->args->simulation_done == false)
	{
		philo->last_meal = get_time() - philo->args->start;
		printf("%-5lld philo #%d "
			"has grabbed fork2\n", philo->last_meal, philo->id);
		pthread_mutex_unlock(&philo->msg);
	}
	else
		pthread_mutex_unlock(&philo->msg);
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
		pthread_mutex_lock(&philo->msg);
		philo->last_meal = get_time() - philo->args->start;
		printf("%-5lld philo #%d is eating\n", philo->last_meal, philo->id);
		pthread_mutex_unlock(&philo->msg);
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
	long long int	time;

	pthread_mutex_lock(&philo->msg);
	if (!philo->dead)
	{
		time = get_time() - philo->args->start;
		printf("%-5lld philo #%d is sleeping\n", time, philo->id);
		pthread_mutex_unlock(&philo->msg);
		usleep(philo->args->time_to_sleep * 1000);
	}
	else
		pthread_mutex_unlock(&philo->msg);
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}

t_bool	think(t_philo *philo)
{
	long long int	time;

	if (!philo->dead)
	{
		pthread_mutex_lock(&philo->msg);
		time = get_time() - philo->args->start;
		printf("%-5lld philo #%d is thinking\n", time, philo->id);
		pthread_mutex_unlock(&philo->msg);
	}
	if (philo->dead || philo->args->simulation_done)
		return (false);
	return (true);
}
