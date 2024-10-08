/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:34:17 by sidiallo          #+#    #+#             */
/*   Updated: 2024/10/08 13:13:47 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->dead_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->count_meal_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->print_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->last_meal_mtx, NULL) != 0)
		return (1);
	return (0);
}

void	init_fork_philo(t_philo *philo, int i)
{
	if (philo->id % 2)
	{
		philo->l_fork = &philo->table->forks[i];
		philo->r_fork = &philo->table->forks[(i + 1) % philo->table->nb_philo];
	}
	else
	{
		philo->r_fork = &philo->table->forks[i];
		philo->l_fork = &philo->table->forks[(i + 1) % philo->table->nb_philo];
	}
}

static int	init_fork(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * (table->nb_philo));
	if (!table->forks)
	{
		free(table->philo);
		return (-1);
	}
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			free(table->philo);
			free(table->forks);
			return (-1);
		}
		init_fork_philo(&table->philo[i], i);
		i++;
	}
	return (0);
}

static int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * (table->nb_philo));
	if (!table->philo)
		return (-1);
	memset(table->philo, 0, sizeof(t_philo) * (table->nb_philo));
	while (i < table->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].table = table;
		table->philo[i].count_meal = 0;
		i++;
	}
	return (0);
}

int	init_table(t_table *table)
{
	if (init_philo(table) != 0)
		return (1);
	if (init_fork(table) != 0)
		return (1);
	if (init_mutex(table) != 0)
		return (free(table->philo), free(table->forks), 1);
	return (0);
}
