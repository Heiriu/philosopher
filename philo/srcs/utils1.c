/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:29:12 by Thbierne          #+#    #+#             */
/*   Updated: 2022/07/06 10:16:58 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (s1[i] != '\0')
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_sleep(int ms)
{
	ms *= 1000;
	while (1)
	{
		if ((ms - 1000000) > 0)
		{
			usleep(1000000);
			ms -= 1000000;
		}
		else
		{
			usleep(ms);
			break;
		}
	}
}

void	print_statut(int nbr_philo, int status, int time_activity)
{
	if (status == 0)
		printf("%i %i has taken a fork\n", time_activity, nbr_philo);
	else if (status == 1)
		printf("%i %i is eating\n", time_activity, nbr_philo);
	else if (status == 2)
		printf("%i %i is sleeping\n", time_activity, nbr_philo);
	else if (status == 3)
		printf("%i %i is thinking\n", time_activity, nbr_philo);
	else if (status == 4)
		printf("%i %i died\n", time_activity, nbr_philo);
}