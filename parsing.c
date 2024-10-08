/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:07:27 by sidiallo          #+#    #+#             */
/*   Updated: 2024/10/08 13:03:23 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	check_limit(char **av)
{
	long long	i;
	long long	res;

	i = 1;
	while (av[i])
	{
		res = ft_atol(av[i]);
		if (res > 2147483648 || res <= 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_table(int ac, char **av, t_table *table)
{
	memset(table, 0, sizeof(*table));
	table->nb_philo = atol(av[1]);
	table->time_to_die = atol(av[2]);
	table->time_to_eat = atol(av[3]);
	table->time_to_sleep = atol(av[4]);
	if (ac == 6)
		table->nb_meal = atol(av[5]);
	return (0);
}

int	parsing(int ac, char **av, t_table *table)
{
	if (check_digit(av) != 0 || check_limit(av) != 0)
	{
		printf("invalid argument\n");
		return (-1);
	}
	if (parse_table(ac, av, table) != 0)
	{
		printf("error argument\n");
	}
	return (0);
}
