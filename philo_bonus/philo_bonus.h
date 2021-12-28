/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:20:38 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 02:20:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

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
	int				argc;
	t_bool			meals_arg;
	t_bool			simulation_done;
	long long int	start;
}	t_args;

typedef struct s_sem
{
	sem_t		forks;
	sem_t		msg;
}	t_sem;

typedef struct s_philo
{
	int				id;
	int				meals;
	t_bool			dead;
	t_sem			*sem;
	t_args			*args;
	long long int	last_meal;
}	t_philo;

long long int	print_msg(t_philo *philo, char *str);
long long int	get_time(void);
int				ft_atoi(const char *str);
t_philo			**init(t_philo **philo, int argc, char **argv);
t_bool			eat(t_philo *philo);
t_bool			sleeping(t_philo *philo);
t_bool			think(t_philo *philo);
t_bool			validation(int argc, char **argv);
void			*cave(void *content);
void			*watch(void *arg);

#endif
