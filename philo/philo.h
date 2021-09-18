/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:17:01 by ssandman          #+#    #+#             */
/*   Updated: 2021/07/06 11:07:54 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil
{
	pthread_t	thread;
	int			left;
	int			right;
	long		lastmeal;
}				t_phil;

typedef struct s_all
{
	int				guys;
	int				life;
	int				feast;
	int				sleep;
	int				meals;
	t_phil			**phils;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*nums;
	pthread_mutex_t	*printer;
	struct timeval	time;
	long int		mstime;
	long int		onset_time;
	int				num;
	int				dead;
	int				feeded;
	int				target;
}				t_all;

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		get_params(int ac, char **av, t_all *all);
int		check_params(t_all *all, int i);
void	get_onsettime(t_all *all);
void	get_time(t_all *all);
int		get_num(t_all *all);
int		init_forks(t_all *all);
int		alloc_phils(t_all *all);
int		init_threads(t_all *all);
int		init_mutex(t_all *all);
void	*phil_prep(void *arg);
void	meal_prep(int current, t_all *all);
int		lifecycle(int current, t_all *all);
void	printer(t_all *all, int current, int msg);

#endif
