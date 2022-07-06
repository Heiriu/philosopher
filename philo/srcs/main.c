/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:41:11 by Thbierne          #+#    #+#             */
/*   Updated: 2022/07/06 10:35:17 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

t_master	*check_alloc_arg(t_master *arg, char **argv, int argc)
{
	int i;
	int y;

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
		return (NULL);
	i = 1;
	arg->time = (struct timeval *)malloc(sizeof(struct timeval));
	arg->nbr_philo = ft_atoi(argv[i++]);
	arg->ttd = ft_atoi(argv[i++]);
	arg->tte = ft_atoi(argv[i++]);
	arg->tts = ft_atoi(argv[i++]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[i++]);
	gettimeofday(arg->time, NULL);
	return (arg);
}

int		main(int argc, char **argv)
{
	t_master	*master;

	master = NULL;
	if (argc < 5 || argc > 6)
	{
		printf("invalid arg, please retry\n");
		return (0);
	}
	master = check_alloc_arg(master, argv, argc);
	if (!master)
		return (0);
	master = creat_list(master);
	//print_list(master);
	//master = alloc_tab_list(master);
	//master = test_thread(master);
	//free_list(master);
	return (0);
}