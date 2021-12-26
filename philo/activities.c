/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:45:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 03:18:29 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	while (1)
	{
		if (!pthread_mutex_lock(&philo->fork1))
		{
			if (!pthread_mutex_lock(&philo->fork2))
				break ;
			else
			{
				pthread_mutex_unlock(&philo->fork1);
				usleep(10);
			}
		}
		else
			usleep(10);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork1);
	pthread_mutex_unlock(&philo->fork2);
}

t_bool	eat(t_philo *philo)
{
	grab_forks(philo);
	while (pthread_mutex_lock(&philo->msg))
		usleep(1);
	if (!philo->dead && philo->meals < philo->args->max_meals)
	{
		philo->last_meal = get_time() - philo->args->start;
		printf("%-5lld philo #%d is eating\n", philo->last_meal, philo->id);
		pthread_mutex_unlock(&philo->msg);
		usleep(philo->args->time_to_eat * 1000);
		drop_forks(philo);
		philo->meals++;
	}
	else
	{
		pthread_mutex_unlock(&philo->msg);
		drop_forks(philo);
	}
	if (philo->dead)
		return (false);
	if (philo->args->meals_arg && philo->meals >= philo->args->max_meals)
		return (false);
	return (true);
}

t_bool	sleeping(t_philo *philo)
{
	long long int	time;

	while (pthread_mutex_lock(&philo->msg))
		usleep(100);
	if (!philo->dead)
	{
		time = get_time() - philo->args->start;
		printf("%-5lld philo #%d is sleeping\n", time, philo->id);
		pthread_mutex_unlock(&philo->msg);
		usleep(philo->args->time_to_sleep * 1000);
	}
	else
		pthread_mutex_unlock(&philo->msg);
	if (philo->dead)
		return (false);
	return (true);
}

t_bool	think(t_philo *philo)
{
	long long int	time;

	while (pthread_mutex_lock(&philo->msg))
		usleep(1);
	if (!philo->dead)
	{
		time = get_time() - philo->args->start;
		printf("%-5lld philo #%d is thinking\n", time, philo->id);
		pthread_mutex_unlock(&philo->msg);
	}
	else
		pthread_mutex_unlock(&philo->msg);
	if (philo->dead)
		return (false);
	return (true);
}
