/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_loops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:40:52 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/22 22:16:00 by jofelipe         ###   ########.fr       */
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
	while (i < 10000000)
	{
		pthread_mutex_lock(&mutex);
		++var;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	printf("var is now %d\n", var);
	return (content);
}

//by separating the loops we ensure that threads run in parallel
int	main(void)
{
	pthread_t	th[4];

	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &function1, NULL) != 0)
			perror("Threading failed");
		printf("thread %d started\n", i);
	}
	for (int i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Thread join failed");
		printf("thread %d finished\n", i);
	}
}
