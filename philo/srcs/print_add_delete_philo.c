/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add_delete_philo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:30:36 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/13 09:48:15 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	print_list(t_master *master)
{
	t_philo	*philo;

	printf("nbr:%i\nttd:%i\ntte:%i\n", master->nbr_philo, master->ttd, master->tte);
	printf("tts:%i\nmust_eat:%i\n", master->tts, master->must_eat);
	philo = master->first;
	while (philo)
	{
		printf("philo_nbr=%i\n", philo->philo_nbr);
		philo = philo->next;
	}
}

t_philo	*add_first_philo(int nbr, t_master *master)
{
	t_philo	*new;
	
	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->philo_nbr = nbr;
	new->master = master;
	pthread_mutex_init(&new->r_fork, NULL);
	new->next = NULL;
	return (new);
}

t_philo	*add_last_philo(t_philo *philo, int nbr, t_master *master)
{
	t_philo	*new;
	t_philo	*tmp;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->philo_nbr = nbr;
	new->master = master;
	pthread_mutex_init(&new->r_fork, NULL);
	new->next = NULL;
	tmp = philo;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->l_fork = &tmp->r_fork;
	return (philo);
}

t_philo	*delete_first_philo(t_philo *philo)
{
	t_philo	*cp;

	if (philo)
	{
		cp = philo->next;
		pthread_mutex_destroy(&philo->r_fork);
		free(philo);
		return (cp);
	}
	return (NULL);
}

void	free_list(t_master *master)
{
	t_philo	*tmp;

	tmp = master->first;
	while (tmp)
		tmp = delete_first_philo(tmp);
	free(master);
}