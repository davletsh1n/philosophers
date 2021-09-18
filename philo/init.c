/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:24:31 by ssandman          #+#    #+#             */
/*   Updated: 2021/07/06 11:04:11 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_all *all)
{
	int	i;

	i = 0;
	all->forks = malloc((sizeof(pthread_mutex_t) * all->guys));
	while (i < all->guys)
	{
		if (pthread_mutex_init(&all->forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	alloc_phils(t_all *all)
{
	int	i;

	i = 0;
	all->phils = malloc((sizeof(t_phil) * all->guys));
	if (!all->phils)
		return (-1);
	while (i < all->guys)
	{
		all->phils[i] = malloc(sizeof(t_phil));
		if (!all->phils[i])
			return (-1);
		i++;
	}
	return (0);
}

int	init_threads(t_all *all)
{
	int	i;

	i = 0;
	alloc_phils(all);
	while (i < all->guys)
	{
		pthread_create(&all->phils[i]->thread, NULL, phil_prep, all);
		i++;
	}
	return (0);
}

int	init_mutex(t_all *all)
{
	all->nums = malloc(sizeof(pthread_mutex_t));
	if (!all->nums)
		return (-1);
	if (pthread_mutex_init(all->nums, NULL) != 0)
		return (-1);
	all->printer = malloc(sizeof(pthread_mutex_t));
	if (!all->printer)
		return (-1);
	if (pthread_mutex_init(all->printer, NULL) != 0)
		return (-1);
	return (0);
}
