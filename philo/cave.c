/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:42:39 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/26 00:47:53 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cave(void *content)
{
	t_philo	*philo;

	philo = (t_philo *)content;
	while (eat(philo) && sleeping(philo) && think(philo))
		continue ;
	return (content);
}
