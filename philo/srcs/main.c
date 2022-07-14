/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:41:11 by Thbierne          #+#    #+#             */
/*   Updated: 2022/07/14 10:26:42 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

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
	master = creat_list(master);
	master = start_thread(master);
	master = join_thread(master);
	free_list(master);
	return (0);
}