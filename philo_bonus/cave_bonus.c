/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:58:41 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/28 02:07:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	exit(EXIT_SUCCESS);
}
