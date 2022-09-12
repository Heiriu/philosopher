/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:35:09 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/09 11:44:06 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_together(t_philo *philo)
{
	static int	i;

	pthread_mutex_lock(&philo->master->aff);
	if (i == 1)
	{
		pthread_mutex_unlock(&philo->master->aff);
		return ;
	}
	while (get_time_pass(philo->master->launch_time) < 100)
	{
	}
	gettimeofday(&philo->master->launch_time, NULL);
	i++;
	pthread_mutex_unlock(&philo->master->aff);
}

void	philo_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->master->aff);
	if (philo->master->dead != 0)
	{
		pthread_mutex_unlock(&philo->master->aff);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_unlock(&philo->master->aff);
	gettimeofday(&philo->l_meal, NULL);
	display(philo, 1);
	ft_sleep(philo, philo->master->tte);
	pthread_mutex_lock(&philo->master->aff);
	if (philo->master->dead != 0)
	{
		pthread_mutex_unlock(&philo->master->aff);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_unlock(&philo->master->aff);
	philo->nom++;
	pthread_mutex_unlock(philo->l_fork);
	philo->status = 2;
}

void	philo_is_sleeping(t_philo *philo)
{
	display(philo, 2);
	ft_sleep(philo, philo->master->tts);
	if (philo->master->dead != 0)
		return ;
	philo->status = 3;
}

void	philo_is_thinking(t_philo *philo)
{
	display(philo, 2);
	if (philo->master->nbr_philo % 2 == 1)
		ft_sleep(philo, philo->master->tte * 2 - philo->master->tts);
	else if (philo->master->tte >= philo->master->tts)
		ft_sleep(philo, philo->master->tte - philo->master->tts);
	if (philo->master->dead != 0)
		return ;
	philo->status = 1;
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;
	int		y;

	philo = (t_philo *)arg;
	start_together(philo);
	if (philo->master->nom == 0)
		return (0);
	gettimeofday(&philo->l_meal, NULL);
	starting_routine(philo);
	catch_var(philo, &i, &y);
	while (y == 0 && i != philo->master->nbr_philo)
	{
		if (philo->status == 1 && philo->master->dead == 0)
			philo_eating(philo);
		else if (philo->status == 2 && philo->master->dead == 0)
			philo_is_sleeping(philo);
		else if (philo->status == 3 && philo->master->dead == 0)
			philo_is_thinking(philo);
		catch_var(philo, &i, &y);
	}
	if (philo->status == 4 && philo->master->dead != 2)
		print_death(philo);
	return (0);
}
