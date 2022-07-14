/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:14:27 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/14 14:47:36 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

unsigned long	get_time_pass(struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (return_time(&time, &now));
}

unsigned long	return_time(struct timeval *old, struct timeval *present)
{
	return (((present->tv_sec - old->tv_sec) *1000000 + (present->tv_usec - old->tv_usec)) / 1000);
}
