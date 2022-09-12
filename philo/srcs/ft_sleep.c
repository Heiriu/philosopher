/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:38:41 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 13:26:19 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep2(int ms)
{
	if (ms > 100)
	{
		usleep(100000);
		ms = ms - 100;
	}
	else
	{
		usleep(ms * 1000);
		ms = 0;
	}
	return (ms);
}

void	detect_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->master->aff);
	if (philo->master->dead != 2)
		philo->master->dead = 1;
	philo->status = 4;
	pthread_mutex_unlock(&philo->master->aff);
}

void	ft_sleep(t_philo *philo, int ms)
{
	int	i;
	int	j;

	i = 0;
	pthread_mutex_lock(&philo->master->aff);
	j = philo->master->dead;
	if ((get_time_pass(philo->l_meal) + ms) >= philo->master->ttd)
	{
		ms = philo->master->ttd - get_time_pass(philo->l_meal);
		i = 1;
	}
	pthread_mutex_unlock(&philo->master->aff);
	while (ms > 0 && j == 0)
	{
		ms = ft_sleep2(ms);
		pthread_mutex_lock(&philo->master->aff);
		j = philo->master->dead;
		pthread_mutex_unlock(&philo->master->aff);
	}
	if (i == 1)
		detect_die(philo);
}
