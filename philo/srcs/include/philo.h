/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:37:50 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/06 10:50:57 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_master t_master;
typedef struct s_philo t_philo;

struct s_philo
{
	int 			philo_nbr;
	pthread_t		philosopher;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_philo 		*next;
	t_master		*master;
};

struct s_master
{
	t_philo 		*first;
	struct timeval	*time;
	int				nbr_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				must_eat;
};

t_master	*creat_list(t_master *master);
t_master	*alloc_tab_list(t_master *master);

void		print_list(t_master *philo);
t_philo		*add_first_philo(int nbr);
t_philo		*add_last_philo(t_philo *philo, int nbr);
t_philo		*delete_first_philo(t_philo *philo);
void		free_list(t_master *master);

t_master	*check_alloc_arg(t_master *arg, char **argv, int argc);
int			main(int argc, char **argv);

t_master     *test_thread(t_master *master);
void		*routine(void *arg);
void		philo_is_eating(t_philo *philo);

int			ft_get_len(int n);
char		*ft_create_str(int len, int n, int neg, char *str);
char		*ft_itoa(int n);
int			ft_get_retour(int retour, int somme, int signe);
int			ft_atoi(const char *str);

char		*ft_strdup(const char *s1);
void		ft_sleep(int ms);
void		print_statut(int nbr_philo, int status, int time_activity);

time_t		get_time_pass(struct timeval *time);

# endif