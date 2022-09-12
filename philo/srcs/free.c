/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:07:59 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 13:20:14 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*free_philo(t_philo *philo)
{
	t_philo	*cp;

	if (philo)
	{
		cp = philo->next;
		pthread_mutex_destroy(&philo->r_fork);
		free (philo);
		return (cp);
	}
	return (NULL);
}

void	free_master(t_master *master)
{
	while (master->philo)
		master->philo = free_philo(master->philo);
	pthread_mutex_destroy(&master->aff);
	free(master);
}
