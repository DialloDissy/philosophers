/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:55:36 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/22 23:35:11 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int dinner_finish(t_table *table)
{
    int ret;

    ret = 0;
    pthread_mutex_lock(&table->dead_mtx);
    if(table->is_dead)
        ret = 1 ;
    pthread_mutex_lock(&table->dead_mtx);
    return (ret);
}
void    set_death(t_table   *table)
{
    pthread_mutex_lock(&table->dead_mtx);
    table->is_dead = 1 ;
    pthread_mutex_unlock(&table->meal_mtx);
}

int check_death(t_philo *philo)
{
    int time;

    pthread_mutex_lock(&philo->table->last_meal_mtx);
    time = get_time() - philo->last_meal;
    pthread_mutex_unlock(&philo->table->last_meal_mtx);
    if(time >= philo->table->time_to_die)
    {
        set_death(philo->table);
        usleep(1000);
        print_msg(philo, DIED);
        return(1);
    }
    return(0);
}

int handle_end(t_table *table)
{
    int i;
    int ret;

    ret = 1;
    i = 0;
    while(i < table->nb_philo)
    {
        if(check_death(&table->philo[i]))
            return(1);
        if(table->nb_meal)
        {
            pthread_mutex_lock(&table->count_meal_mtx);
            if(table->philo[i].count_meal = table->nb_meal)
                ret = 0;
            pthread_mutex_unlock(&table->count_meal_mtx);
        }
        i++;
    }
    if(table->nb_meal && ret)
        return(set_death(table),1);
    else
        return(0);
}


void *monitor(void *arg)
{
    t_table *table;

    table = (t_table *)arg;
    wait_all_thread(table->time_start);
    while(!dinner_finish(table))
    {
        if(handle_end(table))
            break;
    }
    return(NULL);
}
