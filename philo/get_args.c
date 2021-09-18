/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:21:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/07/06 12:11:52 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_params(t_all *all, int i)
{
	if (all->guys <= 0)
		return (0);
	if (all->life <= 0)
		return (0);
	if (all->feast <= 0)
		return (0);
	if (all->sleep <= 0)
		return (0);
	if (i == 2 && all->meals <= 0)
		return (0);
	return (-1);
}

int	get_params(int ac, char **av, t_all *all)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		all->guys = ft_atoi(av[1]);
		all->life = ft_atoi(av[2]);
		all->feast = ft_atoi(av[3]);
		all->sleep = ft_atoi(av[4]);
		i = 1;
	}
	if (ac == 6)
	{
		all->meals = ft_atoi(av[5]);
		i = 2;
	}
	all->target = all->guys * all->meals;
	if (all->guys == 1 && all->meals == 0)
		all->target = 1;
	if (i && check_params(all, i))
		return (0);
	else
		return (-1);
}

void	get_onsettime(t_all *all)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	all->onset_time = (tmp.tv_sec * 1000000 + tmp.tv_usec);
}

void	get_time(t_all *all)
{
	gettimeofday(&all->time, NULL);
	all->mstime = all->time.tv_sec * 1000000
		 + all->time.tv_usec - all->onset_time;
}

int	get_num(t_all *all)
{
	int	num;

	pthread_mutex_lock(all->nums);
	num = all->num++;
	pthread_mutex_unlock(all->nums);
	if (num > 0)
	{
		all->phils[num]->left = num;
		all->phils[num]->right = num - 1;
	}
	else
	{
		all->phils[num]->left = 0;
		all->phils[num]->right = all->guys - 1;
	}
	return (num);
}
