/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:35:13 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/16 23:51:33 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"





// int philo_routine(void *arg)
// {
// 	t_philo *philo;

// 	philo = (t_philo *)arg;
// 	pthread_mutex_lock(&philo->table->last_meal_mtx);
// 	philo->last_meal = philo->table->time_start;
// 	pthread_mutex_unlock(&philo->table->last_meal_mtx);
// 	wait_all_thread(philo->table->time_start);
// 	if(philo->id % 2)
// 	{
// 		ft_usleep(philo->table->time_to_eat,philo->table)
// 	}
	
	
	
	
// }


// int dinner(t_table *table)
// {
//     int i;

//     i = 0;
//     table->time_start = get_the_time() +(table->nb_philo * 20);
// 	printf("%d\n");
//     if(i < table->nb_philo)
//     {
//         table->philo[i].last_meal = table->time_start;
// 		if(pthread_create(&table->philo[i].thread_id,NULL,&philo_routine,&table->philo[i]));
// 			return(1);
// 		i++;
//     }
// }

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
		return (5); // exit clearly
	}
	if (parsing(ac, av, table) != 0)
		return (-1); // exit clearly
	if(init_table(table) != 0)
		return(-1);
    // if(dinner(table) != 0)
    //     return(-5); // exit correctly
	printf("nice parsing\n");
	exit_philo(table);
}
