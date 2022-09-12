/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:16:44 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 15:09:34 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_nom(char **argv, int i, int y)
{
	if (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			if (argv[i][y] < '0' || argv[i][y] > '9')
				return (-1);
			y++;
		}
	}
	return (0);
}

int	check_arg_argv(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[++i] && i < 5)
	{
		y = 0;
		if (argv[i][y] == '0' || argv[i][y] == '-')
			return (-1);
		while (argv[i][y])
		{
			if (argv[i][y] < '0' || argv[i][y] > '9')
				return (-1);
			y++;
		}
	}
	return (check_nom(argv, i, y));
}

int	check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "wrong number of argument\n", 26);
		return (-1);
	}
	if (check_arg_argv(argv) == -1)
	{
		write(1, "wrong argument value\n", 22);
		return (-1);
	}
	return (0);
}

t_master	*alloc_arg(char **argv)
{
	t_master	*master;
	int			i;

	i = 1;
	master = (t_master *)malloc(sizeof(t_master));
	if (!master)
		exit(1);
	master->nbr_philo = ft_atoi(argv[i++]);
	master->ttd = ft_atoi(argv[i++]);
	master->tte = ft_atoi(argv[i++]);
	master->tts = ft_atoi(argv[i++]);
	if (argv[i])
		master->nom = ft_atoi(argv[i]);
	else
		master->nom = -1;
	master->time_eat = 0;
	master->dead = 0;
	pthread_mutex_init(&master->aff, NULL);
	gettimeofday(&master->launch_time, NULL);
	return (master);
}
