/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:42:39 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 15:41:22 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cave(void *content)
{
	t_philo		*philo;
	pthread_t	reaper;

	philo = (t_philo *)content;
	if (philo->id % 2)
		usleep(5000);
	pthread_create(&reaper, NULL, &watch, content);
	pthread_detach(reaper);
	while (eat(philo) && sleeping(philo) && think(philo))
		continue ;
	return (content);
}
