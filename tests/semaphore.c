/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:12:16 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/27 18:28:02 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <semaphore.h>

sem_t		g_semaphore;

void	*routine(void *arg)
{
	sem_wait(&g_semaphore);
	sleep(1);
	printf("%d hello\n", *(int *)arg);
	free(arg);
	sem_post(&g_semaphore);
	return (NULL);
}

int	main(void)
{
	pthread_t	t[5];
	int			i;
	int			*j;

	//param 2: multiple threads = 0 multiple processes = 1
	//param 3: number of times the semaphore can be activated
	sem_init(&g_semaphore, 0, 2);
	i = -1;
	while (++i < 5)
	{
		j = malloc(sizeof(int));
		*j = i;
		pthread_create(&t[i], NULL, &routine, (void *)j);
	}
	i = -1;
	while (++i < 5)
		pthread_join(t[i], NULL);
	return (0);
}
