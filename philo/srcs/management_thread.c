/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:57:09 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 13:26:28 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	launch_thread(t_master *master)
{
	t_philo	*cpy;

	cpy = master->philo;
	while (cpy)
	{
		pthread_create(&cpy->philo, NULL, &routine, cpy);
		cpy = cpy->next;
	}
	cpy = master->philo;
	while (cpy)
	{
		pthread_join(cpy->philo, NULL);
		cpy = cpy->next;
	}
}

t_philo	*alloc_fork(t_philo *philo)
{
	t_philo	*cpy;

	cpy = philo;
	while (cpy->next)
		cpy = cpy->next;
	cpy->l_fork = &philo->r_fork;
	philo->l_fork = &philo->next->r_fork;
	return (philo);
}

void	alloc_thread(t_master *master)
{
	int	i;

	i = 0;
	while (++i <= master->nbr_philo)
		master->philo = alloc_philo(master->philo, i, master);
	if (master->nbr_philo >= 2)
		master->philo = alloc_fork(master->philo);
	launch_thread(master);
}
