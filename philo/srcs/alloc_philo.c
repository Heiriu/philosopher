/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:01:11 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/09 11:39:40 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	catch_var(t_philo *philo, int *i, int *y)
{
	pthread_mutex_lock(&philo->master->aff);
	*i = philo->master->time_eat;
	*y = philo->master->dead;
	pthread_mutex_unlock(&philo->master->aff);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	display(philo, 0);
	display(philo, 0);
	philo_is_eating(philo);
	pthread_mutex_lock(&philo->master->aff);
	if (philo->nom == philo->master->nom)
		philo->master->time_eat++;
	pthread_mutex_unlock(&philo->master->aff);
}

t_philo	*alloc_philo(t_philo *philo, int nbr, t_master *master)
{
	t_philo	*new;
	t_philo	*tmp;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		exit (1);
	new->nbr = nbr;
	new->status = 1;
	new->master = master;
	new->nom = 0;
	pthread_mutex_init(&new->r_fork, NULL);
	new->next = NULL;
	if (nbr == 1)
		return (new);
	tmp = philo;
	while (tmp->next)
		tmp = tmp->next;
	tmp->l_fork = &new->r_fork;
	tmp->next = new;
	return (philo);
}
