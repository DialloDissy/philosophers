/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:31:42 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/23 20:44:32 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void exit_philo(t_table *table)
{
    int i;

    i = 0;
    while(i < table->nb_philo)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
    if(table->forks)
        free(table->forks);
    if(table->philo)
        free(table->philo);
    pthread_mutex_destroy(&table->print_mtx);
    pthread_mutex_destroy(&table->last_meal_mtx);
    pthread_mutex_destroy(&table->count_meal_mtx);
    if(table)
        free(table);
}