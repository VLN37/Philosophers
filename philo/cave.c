/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:42:39 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/31 03:18:07 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cave(void *content)
{
	t_philo		*philo;
	pthread_t	the_devil;

	philo = (t_philo *)content;
	if (philo->id % 2)
		usleep(5000);
	pthread_create(&the_devil, NULL, &see_you_in_hell, content);
	pthread_detach(the_devil);
	while (eat(philo) && _sleep(philo) && think(philo))
		continue ;
	return (content);
}
