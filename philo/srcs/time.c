/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:14:27 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/06 10:30:02 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

time_t		get_time_pass(struct timeval *time)
{
	struct timeval *now;
	time_t			present;

	now = (struct timeval *)malloc(sizeof(struct timeval));
	gettimeofday(now, NULL);
	present = (now->tv_usec - time->tv_usec) / 1000;
	free(now);
	return (present);
}