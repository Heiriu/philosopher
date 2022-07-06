/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:48:32 by thbierne          #+#    #+#             */
/*   Updated: 2022/06/17 11:57:27 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

t_master	*creat_list(t_master *master)
{
	t_philo	*tmp;
	int 	i;

	i = 1;
	master->first = add_first_philo(i);
	while (++i <= master->nbr_philo)
		master->first = add_last_philo(master->first, i);
	tmp = master->first;
	while (tmp->next)
		tmp = tmp->next;
	master->first->l_fork = &tmp->r_fork;
	return (master);
}

t_master	*alloc_tab_list(t_master *master)
{
	t_philo	*now;

	if (!master)
		exit(EXIT_FAILURE);
	now = master->first;
	while (now)
	{
		pthread_create(&now->philosopher, NULL, &routine, now);
		now = now->next;
	}
	return (master);
}
