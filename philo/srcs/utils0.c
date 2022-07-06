/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:51:10 by Thbierne          #+#    #+#             */
/*   Updated: 2022/03/09 14:20:24 by Thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int			ft_get_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_create_str(int len, int n, int neg, char *str)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = n;
	len = ft_get_len(n);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		n = -n;
	return (ft_create_str(len, n, neg, str));
}

int				ft_get_retour(int retour, int somme, int signe)
{
	if (retour >= 20 && signe == -1)
		retour = 0;
	else if (retour >= 20 && signe == 1)
		retour = -1;
	else
		retour = somme * signe;
	return (retour);
}

int				ft_atoi(const char *str)
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