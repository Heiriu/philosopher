/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:49:00 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 15:07:05 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_master	*master;

	if (check_arg(argc, argv) == -1)
		return (0);
	master = alloc_arg(argv);
	alloc_thread(master);
	free_master(master);
	return (0);
}
