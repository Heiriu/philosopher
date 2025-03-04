/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:29:12 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 13:21:12 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_time_pass(struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (return_time(&time, &now));
}

int	return_time(struct timeval *o, struct timeval *p)
{
	return (((p->tv_sec - o->tv_sec) * 1000000 +(p->tv_usec - o->tv_usec))
		/ 1000);
}
