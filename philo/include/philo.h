/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:11:17 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/09 11:40:25 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_master	t_master;
typedef struct s_philo	t_philo;

struct s_philo
{
	int				nbr;
	int				status;
	int				nom;
	struct timeval	l_meal;
	pthread_t		philo;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_master		*master;
	t_philo			*next;
};

struct s_master
{
	t_philo			*philo;
	pthread_mutex_t	aff;
	struct timeval	launch_time;
	int				nbr_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nom;
	int				time_eat;
	int				dead;
};

int			check_arg_argv(char **argv);
int			check_arg(int argc, char **argv);
t_master	*alloc_arg(char **argv);

void		catch_var(t_philo *philo, int *i, int *y);
void		philo_eating(t_philo *philo);
void		philo_is_eating(t_philo *philo);
t_philo		*alloc_philo(t_philo *philo, int nbr, t_master *master);

void		launch_thread(t_master *master);
t_philo		*alloc_fork(t_philo *philo);
void		alloc_thread(t_master *master);

void		*routine(void *arg);

int			return_time(struct timeval *old, struct timeval *present);
int			get_time_pass(struct timeval time);

void		ft_sleep(t_philo *philo, int ms);

void		display(t_philo *philo, int nbr);

int			ft_atoi(const char *str);
void		print_master(t_master *master);
void		starting_routine(t_philo *philo);
void		print_death(t_philo *philo);

void		free_master(t_master *master);

#endif
