/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:44:38 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/22 22:15:33 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				var = 0;
pthread_mutex_t	mutex;

void	*function1(void *content)
{
	int	i;

	i = 0;
	(void)content;
	pthread_mutex_lock(&mutex);
	while (i < 999999)
	{
		++var;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (content);
}

void	*function2(void *content)
{
	int	i;

	i = 0;
	(void)content;
	pthread_mutex_lock(&mutex);
	while (i < 999999)
	{
		++var;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (content);
}

//race conditions overlap the two threads
//to solve this we stop the thread with mutex on lines 24 and 40
int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_mutex_init(&mutex, NULL);
	var = 2;
	pthread_create(&t1, NULL, &function1, NULL);
	pthread_create(&t2, NULL, &function2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("the final var value: %d\n", var);
	pthread_mutex_destroy(&mutex);
}
