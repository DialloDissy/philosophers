/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:35:13 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/24 23:57:48 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void	number_meal(t_table *table)
{
	int i;

	i = 0;
	if(table->nb_meal == 0)
		return;
	while(i < table->nb_philo)
	{
		if(table->philo[i].count_meal == table->nb_meal)
			i++;
		else
			break;
	}
	if( i == table->nb_philo)
	{
		pthread_mutex_lock(&table->print_mtx);
		printf(M"All philos are full ;) \n"RST);
		pthread_mutex_unlock(&table->print_mtx);
	}
}



void	print_msg(t_philo *philo, int msg)
{
	pthread_mutex_lock(&philo->table->print_mtx);
	if (dinner_finish(philo->table) && msg != DIED)
	{
		pthread_mutex_unlock(&philo->table->print_mtx);
		return ;
	}
	if (msg == DIED)
	{
		printf("%s%09zu %d died%s\n", RED, get_the_time() - philo->table->time_start, philo->id, RST);
		set_death(philo->table);
	}
	else if (msg == EAT)
		printf("%s%09zu %d is eating%s\n", G,get_the_time() - philo->table->time_start, philo->id, RST);
	else if (msg == SLEEP)
		printf("%s%09zu %d is sleeping%s\n", B,get_the_time() - philo->table->time_start, philo->id, RST);
	else if (msg == THINK)
		printf("%s%09zu %d is thinking%s\n", Y,get_the_time() - philo->table->time_start, philo->id, RST);
	else if (msg == FORK)
		printf("%s%09zu %d has taken a fork%s\n", W,get_the_time() - philo->table->time_start, philo->id, RST);
	pthread_mutex_unlock(&philo->table->print_mtx);
}


void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->last_meal_mtx);
	philo->last_meal = philo->table->time_start;
	pthread_mutex_unlock(&philo->table->last_meal_mtx);
	wait_all_thread(philo->table->time_start);
	if(philo->table->nb_philo == 1)
	{
		ft_usleep(philo->table->time_to_die,philo->table);
		if(!dinner_finish(philo->table))
			print_msg(philo,DIED);
		return(NULL);
	}
	if(philo->id % 2)
		ft_usleep(philo->table->time_to_eat,philo->table);
	while(!dinner_finish(philo->table))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	} 
	return(NULL);
}


int dinner(t_table *table)
{
    int i;

    i = 0;
    table->time_start = get_the_time() +(table->nb_philo * 20);
    while(i < table->nb_philo)
    {
        table->philo[i].last_meal = table->time_start;
		if(pthread_create(&table->philo[i].thread_id,NULL,&philo_routine,&table->philo[i]))
			return(1);
		i++;
	}
	if(pthread_create(&table->monitor,NULL,&monitor,table))
	 	return(-1); //handling this case
	i = 0;
	while(i < table->nb_philo)
	{
		if(pthread_join(table->philo[i].thread_id,NULL))
			return(-1);
		i++;
	}
	number_meal(table);
	if(pthread_join(table->monitor,NULL))
			return(-1);
	return(0);
}

int	main(int ac, char **av)
{
	(void)av;
	t_table *table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (-1);
	if (ac != 5 && ac != 6)
	{
		printf(" The number of characters is wrong \n");
		return (free(table), -1); // exit clearly
	}
	if (parsing(ac, av, table) != 0)
		return(free(table),1);
	if( init_table(table) != 0)
		return (printf("erro init table\n)",free(table),1));
    if(dinner(table) != 0) // exit correctly
		return (exit_philo(table),1);
	exit_philo(table);
	return (0);
}
