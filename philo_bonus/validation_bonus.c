/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:16:14 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 00:27:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_bool	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

static t_bool	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i < argc)
	{
		while (argv[i][++j])
			if (is_digit(argv[i][j]) == false)
				return (false);
		j = -1;
	}
	return (true);
}

t_bool	validation(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("usage: ./philo num_of_philo time_to_die time_to_eat "
			"time_to_sleep (optional)times_to_eat\n");
		return (false);
	}
	if (check_args(argc, argv) == false)
	{
		printf("arguments should be numbers only\n");
		return (false);
	}
	return (true);
}
