/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:42:39 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/13 15:56:43 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

t_master	*check_alloc_arg(t_master *arg, char **argv, int argc)
{
	int i;
	int y;
	struct timeval present;

	i = 1;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y] >= '0' && argv[i][y] <= '9')
			y++;
		if (argv[i][y] == '\0')
			i++;
		else
		{
			printf("invalid arg, please retry\n");
			return (NULL);
		}
	}
	arg = (t_master *)malloc(sizeof(t_master));
	if (!arg)
		exit(EXIT_FAILURE);
	if (!arg)
		exit(EXIT_FAILURE);
	i = 1;
	arg->nbr_philo = ft_atoi(argv[i++]);
	arg->ttd = ft_atoi(argv[i++]);
	arg->tte = ft_atoi(argv[i++]);
	arg->tts = ft_atoi(argv[i++]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[i++]);
	gettimeofday(&present, NULL);
	arg->time = present;
	arg->death = 0;
	return (arg);
}