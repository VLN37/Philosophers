/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:12:32 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/22 22:15:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*function(void *arg)
{
	int	index;

	index = *(int *)arg;
	printf("%d ", primes[index]);
	free(arg);
	return (arg);
}

/*
 * notice how if i don't malloc arguments in line 36 the value stored in memory
 * may change before the thread is actually started, since i pass it as
 * reference
*/
int	main(void)
{
	pthread_t	th[10];
	int			i;
	int			*arg;

	for (i = 0; i < 10; i++)
	{
		arg = malloc(sizeof(int));
		*arg = i;
		if (pthread_create(&th[i], NULL, &function, arg) != 0)
			perror("Threading failed");
	}
	for (i = 0; i < 10; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Thread join failed");
	}
}
