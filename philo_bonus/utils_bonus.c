/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:22:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/30 12:37:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	msleep(long long int time)
{
	long long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(100);
}

long long int	print_msg(t_philo *philo, char *str)
{
	long long int	time;

	time = get_time() - philo->args->start;
	printf("%-5lld philo #%d %s\n", time, philo->id, str);
	return (time);
}

long long int	get_time(void)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));
}

static int	validate_atoi(const char *str, int *ptrsign, int *ptri)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*ptrsign *= -1;
		i++;
	}
	*ptri = i;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	return (1);
}

//receives a string and returns it as an int, if valid
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!validate_atoi(str, &sign, &i))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (result);
		else
			result = (result * 10) + (str[i] - '0') * sign;
		i++;
	}
	return (result);
}
