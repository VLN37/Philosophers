/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:07:31 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/21 12:20:53 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	var = 2;

void	*function1(void *content)
{
	(void)content;
	var++;
	sleep(1);
	printf("var pthread1 = %d\n", var);
	return (content);
}

void	*function2(void *content)
{
	(void)content;
	sleep(2);
	printf("var pthread2 = %d\n", var);
	return (content);
}

//notice how variables share the same address space contrary to forks
int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	var = 2;
	pthread_create(&t1, NULL, &function1, NULL);
	pthread_create(&t2, NULL, &function2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
