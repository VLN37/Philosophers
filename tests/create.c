/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:57:19 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/21 12:07:12 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*function(void *content)
{
	(void)content;
	printf("testing pthread create\n");
	sleep(3);
	printf("terminate thread\n");
	return (content);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	//possible that the linux environment does not allow creation of threads
	//second parameter NULL is default paramaters
	pthread_create(&t1, NULL, &function, NULL);
	pthread_create(&t2, NULL, &function, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
