/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:16:47 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 13:09:23 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	display(t_philo *philo, int nbr)
{
	pthread_mutex_lock(&philo->master->aff);
	if (philo->status == 1 && nbr == 0 && philo->master->dead == 0)
		printf("%i %i has taken a fork\n",
			get_time_pass(philo->master->launch_time), philo->nbr);
	else if (philo->status == 1 && nbr == 1 && philo->master->dead == 0)
		printf("%i %i is eating\n",
			get_time_pass(philo->master->launch_time), philo->nbr);
	else if (philo->status == 2 && philo->master->dead == 0)
		printf("%i %i is sleeping\n",
			get_time_pass(philo->master->launch_time), philo->nbr);
	else if (philo->status == 3 && philo->master->dead == 0)
		printf("%i %i is thinking\n",
			get_time_pass(philo->master->launch_time), philo->nbr);
	else if (philo->status == 4 && philo->master->dead == 1 && nbr == 3)
		printf("%i %i died\n",
			get_time_pass(philo->master->launch_time), philo->nbr);
	pthread_mutex_unlock(&philo->master->aff);
}
