/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:55:14 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/07 13:31:15 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_get_retour(int retour, int somme, int signe)
{
	if (retour >= 20 && signe == -1)
		retour = 0;
	else if (retour >= 20 && signe == 1)
		retour = -1;
	else
		retour = somme * signe;
	return (retour);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		somme;
	int		retour;

	retour = 0;
	i = 0;
	signe = 1;
	somme = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		somme = (somme * 10) + (str[i] - 48);
		i++;
		retour++;
	}
	return (ft_get_retour(retour, somme, signe));
}

void	print_master(t_master *master)
{
	printf("nbr_philo: %i\nttd: %i\n", master->nbr_philo, master->ttd);
	printf("tte: %i\ntts: %i\n", master->tte, master->tts);
	printf("nom: %i\n", master->nom);
	printf("launch_time: %i\n", get_time_pass(master->launch_time));
}

void	starting_routine(t_philo *philo)
{
	if (philo->nbr % 2 == 0)
	{
		philo->status = 3;
		display(philo, 2);
		philo->status = 1;
		ft_sleep(philo, philo->master->tte);
	}
	else if (philo->master->nbr_philo == 1)
	{
		display(philo, 0);
		ft_sleep(philo, philo->master->ttd);
		philo->master->dead = 1;
	}
	else if (philo->nbr == philo->master->nbr_philo)
	{
		philo->status = 3;
		display(philo, 2);
		philo->status = 1;
		ft_sleep(philo, (philo->master->tte * 2));
	}
}

void	print_death(t_philo *philo)
{
	display(philo, 3);
	pthread_mutex_lock(&philo->master->aff);
	philo->master->dead = 2;
	pthread_mutex_unlock(&philo->master->aff);
}
