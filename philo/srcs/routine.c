/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:01:49 by thbierne          #+#    #+#             */
/*   Updated: 2022/06/17 14:58:38 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

t_master     *test_thread(t_master *master)
{
	t_philo *now;

	now = master->first;
	while (now)
	{
		pthread_join(now->philosopher, NULL);
		now = now->next;
	}
	return (master);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while(1)
	{
		if (philo->philo_nbr % 2 != 0)
			philo_is_eating(philo);
		else
		{
			printf("%i take a nap\n", philo->philo_nbr);
			ft_sleep(500);
		}
		if (philo->philo_nbr % 2 == 0)
			philo_is_eating(philo);
		else
		{
			printf("%i take a nap\n", philo->philo_nbr);
			ft_sleep(500);
		}
	}
	return (0);
}

void	philo_is_eating(t_philo *philo)
{
	printf("%i is thinking\n", philo->philo_nbr);
	pthread_mutex_lock(&philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	printf("%i take a fork\n", philo->philo_nbr);
	ft_sleep(2000);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}