/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:45:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/25 23:40:17 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	eat(t_philo *philo)
{
	long long int	time;

	while (pthread_mutex_lock(&philo->msg))
		usleep(1);
	if (!philo->dead)
	{
		time = get_time() - philo->args->start;
		printf("%lld philo #%d is eating\n", time, philo->id);
		pthread_mutex_unlock(&philo->msg);
		usleep(philo->args->time_to_eat * 1000);
		philo->meals++;
	}
	else
		pthread_mutex_unlock(&philo->msg);
	if (philo->dead)
		return (false);
	if (philo->args->meals_arg && philo->meals > philo->args->max_meals)
		return (false);
	return (true);
}

t_bool	sleeping(t_philo *philo)
{
	long long int	time;

	while (pthread_mutex_lock(&philo->msg))
		usleep(1);
	if (!philo->dead)
	{
		time = get_time() - philo->args->start;
		printf("%lld philo #%d is sleeping\n", time, philo->id);
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
		printf("%lld philo #%d is thinking\n", time, philo->id);
		pthread_mutex_unlock(&philo->msg);
	}
	else
		pthread_mutex_unlock(&philo->msg);
	if (philo->dead)
		return (false);
	return (true);
}
