/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:48:32 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/13 10:38:26 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

t_master	*creat_list(t_master *master)
{
	t_philo	*tmp;
	int 	i;

	i = 1;
	master->first = add_first_philo(i, master);
	while (++i <= master->nbr_philo)
		master->first = add_last_philo(master->first, i, master);
	tmp = master->first;
	while (tmp->next)
		tmp = tmp->next;
	master->first->l_fork = &tmp->r_fork;
	return (master);
}

t_master	*start_thread(t_master *master)
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

t_master     *join_thread(t_master *master)
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