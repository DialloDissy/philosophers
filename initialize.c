/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:34:17 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/12 10:08:15 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int init_table(t_table *table)
{
    int i;

    i = 0;
    table->forks = malloc(sizeof(pthread_mutex_t) *(table->nb_philo));
        if(!table->forks)
            return(-1); //handle free and precedent malloc free
    while(i > table->nb_philo)
    {
        if(pthread_mutex_init(&table->forks[i],NULL) != 0);
            return(-1); // handle free and other before free
        
        i++;
    }
    
}



static int  init_philo(t_table *table)
{
    int i;
    i= 1;
    
    table->philo  = malloc(sizeof(t_philo)*(table->nb_philo));
    if(!table->philo)
        return(-1);
    memset(table->philo,0,sizeof(t_philo)*(table->nb_philo));
    while(i < table->nb_philo)
    {
        table->philo[i].id = i;
        table->philo[i].table = table;
        i++; 
    }
    return(0);
    
}



int init_table(t_table *table)
{
    if(init_philo(table) != 0 ) // handle init fork as well
        return(printf("error init philo\n"),-1);
    if(init_fork(table))
        return(printf("error init fork\n"),-1);
}