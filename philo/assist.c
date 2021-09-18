/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:19:32 by ssandman          #+#    #+#             */
/*   Updated: 2021/07/06 10:21:16 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	num;

	num = 0;
	neg = 1;
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'
			|| *str == '\n' || *str == ' ') && *str != '\0')
		str++;
	if (*str == '-' && str[1] >= '0' && str[1] <= '9')
	{
		neg = -1;
		return (-1);
	}
	if (*str == '+' && str[1] >= '0' && str[1] <= '9')
		return (-1);
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (num * neg);
}
