/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:37:50 by thbierne          #+#    #+#             */
/*   Updated: 2022/07/13 15:50:36 by thbierne         ###   ########.fr       */
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

//2 = eat
//3 = think
//4 = sleep
//1 = dead

struct s_philo
{
	int 			philo_nbr;
	int				status;
	pthread_t		philosopher;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_philo 		*next;
	t_master		*master;
};

struct s_master
{
	t_philo 		*first;
	struct timeval	time;
	int				nbr_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				must_eat;
	int				death;
};

/* ft_check_arg */

t_master	*check_alloc_arg(t_master *arg, char **argv, int argc);

/* print_add_delete_philo */

void		print_list(t_master *philo);
t_philo		*add_first_philo(int nbr, t_master *master);
t_philo		*add_last_philo(t_philo *philo, int nbr, t_master *master);
t_philo		*delete_first_philo(t_philo *philo);
void		free_list(t_master *master);

/* thread management */

t_master	*creat_list(t_master *master);
t_master	*start_thread(t_master *master);
t_master	*join_thread(t_master *master);

/* routine */

void		*routine(void *arg);
void		philo_is_eating(t_philo *philo);
void		philo_is_eating_start(t_philo *philo);

/* time */

unsigned long	return_time(struct timeval *old, struct timeval *present);
unsigned long	get_time_pass(struct timeval time);

/* utils0 */

int			ft_get_len(int n);
char		*ft_create_str(int len, int n, int neg, char *str);
char		*ft_itoa(int n);
int			ft_get_retour(int retour, int somme, int signe);
int			ft_atoi(const char *str);

/* utils1 */

char		*ft_strdup(const char *s1);
void		ft_sleep(int ms);
void		print_statut(int nbr_philo, int status, int time_activity);

# endif