/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:42:28 by ssandman          #+#    #+#             */
/*   Updated: 2021/07/06 12:49:25 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
* NUM | TIME TO DIE | TIME TO EAT | TIME TO SLEEP
*/

void	monitor(t_all *all)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < all->guys)
		{
			get_time(all);
			if (all->mstime - all->phils[i]->lastmeal > all->life * 1000)
			{
				if (all->target == all->feeded && all->target != 0)
				{
					return ;
				}
				printer(all, i + 1, 5);
				return ;
			}
			i++;
		}
	}
}

void	memfree(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < all->guys)
	{
		pthread_mutex_destroy(&(all->forks[i]));
		i++;
	}
	pthread_mutex_destroy(all->nums);
	pthread_mutex_destroy(all->printer);
	i = 0;
	while (i < all->guys)
	{
		free(all->phils[i]);
		i++;
	}
	free(all->phils);
	free(all->forks);
	free(all->nums);
	free(all->printer);
}

void	finish(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->guys)
	{
		pthread_join(all->phils[i]->thread, NULL);
		i++;
	}
	memfree(all);
}

int	main(int ac, char **av)
{
	int		i;
	t_all	all;

	memset(&all, '\0', sizeof(all));
	all.feeded = 0;
	if (get_params(ac, av, &all))
	{
		printf("Wrong params\n");
		return (1);
	}
	init_forks(&all);
	init_mutex(&all);
	get_onsettime(&all);
	init_threads(&all);
	monitor(&all);
	if (all.dead)
	{
		memfree(&all);
		return (0);
	}
	finish(&all);
	return (0);
}
