/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:48:45 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 01:09:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_args
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				max_meals;
	int				max_philo;
	t_bool			meals_arg;
	void			*forks;
	long long int	start;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				meals;
	pthread_mutex_t	fork1;
	pthread_mutex_t	fork2;
	pthread_mutex_t	msg;
	t_bool			dead;
	t_args			*args;
}	t_philo;

long long int	get_time(void);
void			*cave(void *philo);
t_bool			eat(t_philo *philo);
t_bool			sleeping(t_philo *philo);
t_bool			think(t_philo *philo);
int				ft_atoi(const char *str);
void			init(t_philo **philo, int argc, char **argv);

#endif
