/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:26:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/07/06 13:06:46 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*phil_prep(void *arg)
{
	t_all	*all;
	int		current;

	all = (t_all *)arg;
	current = get_num(all);
	meal_prep(current, all);
}

void	meal_prep(int current, t_all *all)
{
	int	meals;
	int	step;
	int	eaten;

	eaten = 0;
	step = 0;
	meals = all->meals;
	if (meals != 0)
		step = 1;
	else
		meals = 1;
	while (meals)
	{
		if (current % 2 && eaten != 1)
			usleep(5000);
		if (lifecycle(current, all))
			break ;
		meals = meals - step;
		eaten = 1;
	}
}

void	printer(t_all *all, int current, int msg)
{
	get_time(all);
	pthread_mutex_lock(all->printer);
	if (all->dead == 1)
		return ;
	else if (msg == 0)
		printf("%u %d has taken a fork\n", all->mstime / 1000, current);
	else if (msg == 1)
		printf("%u %d has taken a fork\n", all->mstime / 1000, current);
	else if (msg == 2)
		printf("%u %d is eating\n", all->mstime / 1000, current);
	else if (msg == 3)
		printf("%u %d is sleeping\n", all->mstime / 1000, current);
	else if (msg == 4)
		printf("%u %d is thinking\n", all->mstime / 1000, current);
	else if (msg == 5)
	{
		all->dead = 1;
		printf("%u %d died\n", all->mstime / 1000, current);
	}
	pthread_mutex_unlock(all->printer);
	return ;
}

int	lifecycle(int current, t_all *all)
{
	if (all->dead)
		return (-1);
	pthread_mutex_lock(&all->forks[all->phils[current]->left]);
	printer(all, current + 1, 0);
	pthread_mutex_lock(&all->forks[all->phils[current]->right]);
	printer(all, current + 1, 1);
	printer(all, current + 1, 2);
	usleep(all->feast * 1000);
	get_time(all);
	all->phils[current]->lastmeal = all->mstime;
	all->feeded++;
	pthread_mutex_unlock(&all->forks[all->phils[current]->right]);
	pthread_mutex_unlock(&all->forks[all->phils[current]->left]);
	printer(all, current + 1, 3);
	usleep(all->sleep * 1000);
	printer(all, current + 1, 4);
}
