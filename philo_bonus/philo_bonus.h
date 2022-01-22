/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:20:38 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/22 04:32:49 by jofelipe         ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <semaphore.h>

# define DIE "died"
# define PICK_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

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
	int				argc;
	int				max_philo;
	int				*pids;
	t_bool			meals_arg;
	_Atomic t_bool	simulation_done;
	long long int	start;
}	t_args;

typedef struct s_sem
{
	sem_t			*forks;
	sem_t			*msgs;
	sem_t			*table;
}	t_sem;

typedef struct s_philo
{
	int					id;
	int					meals;
	_Atomic t_bool		dead;
	t_sem				*sem;
	t_args				*args;
	_Atomic long long	last_meal;
	void				**ptr;
}	t_philo;

long long int	print_msg(t_philo *philo, char *str);
long long int	get_time(void);
int				ft_atoi(const char *str);
t_philo			**init(t_philo **philo, int argc, char **argv);
t_bool			eat(t_philo *philo);
t_bool			_sleep(t_philo *philo);
t_bool			think(t_philo *philo);
t_bool			validation(int argc, char **argv);
void			*cave(void *content);
void			*see_you_in_hell(void *arg);
void			cleanup(t_philo **philo, int max_philo, int *pid);
void			cleanup_child(t_philo **philo, t_philo *me, int exit_code);
void			msleep(long long int time);
void			spawn_processes(t_philo **philo);
void			wait_patiently(t_philo **philo);
void			kill_threads(t_philo **philo);

#endif
