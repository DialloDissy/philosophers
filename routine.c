/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:08:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/24 23:37:03 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void    eating(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    print_msg(philo,FORK);
    pthread_mutex_lock(philo->r_fork);
    print_msg(philo,FORK);
    if(!dinner_finish(philo->table))
    {
        print_msg(philo,EAT);
        ft_usleep(philo->table->time_to_eat,philo->table);
        pthread_mutex_lock(&philo->table->last_meal_mtx);
        philo->last_meal = get_the_time();
        pthread_mutex_unlock(&philo->table->last_meal_mtx);
        if(!dinner_finish(philo->table))
        {
            pthread_mutex_lock(&philo->table->count_meal_mtx);
            philo->count_meal++;
            pthread_mutex_unlock(&philo->table->count_meal_mtx);
        }
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
    }
    else
    {
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
    }
}

void    sleeping(t_philo *philo)
{
    if(!dinner_finish(philo->table))
    {
        print_msg(philo,SLEEP);
        ft_usleep(philo->table->time_to_sleep,philo->table);
    }
    
}

void    thinking(t_philo *philo)
{
    size_t time_thinking;
    
    if(dinner_finish(philo->table))
        return;
    print_msg(philo,THINK);
    if(philo->table->nb_philo % 2 == 0)
        return;
    else if(philo->table->time_to_eat < philo->table->time_to_sleep)
        return;
    else
        time_thinking = philo->table->time_to_eat;
    ft_usleep(time_thinking,philo->table);
        
    
}

