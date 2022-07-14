/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:01:49 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/14 10:05:06 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	if (philo->philo_nbr % 2 != 0)
		ft_sleep(1);
	while(philo->master->death == 0)
	{
		philo_is_eating(philo);
		printf("%ld %i take a nap\n", get_time_pass(philo->master->time), philo->philo_nbr);
		ft_sleep(philo->master->tts);
	}
	return (0);
}

void	philo_is_eating(t_philo *philo)
{
	printf("%ld %i is thinking\n", get_time_pass(philo->master->time), philo->philo_nbr);
	pthread_mutex_lock(&philo->r_fork);
	printf("%ld %i take a fork\n", get_time_pass(philo->master->time), philo->philo_nbr);
	pthread_mutex_lock(philo->l_fork);
	printf("%ld %i take a fork\n", get_time_pass(philo->master->time), philo->philo_nbr);
	printf("%ld %i is eating\n", get_time_pass(philo->master->time), philo->philo_nbr);
	ft_sleep(philo->master->tte);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
