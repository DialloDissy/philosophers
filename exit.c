/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:31:42 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/16 23:51:03 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void exit_philo(t_table *table)
{
    if(table->forks)
        free(table->forks);
    if(table->philo)
        free(table->philo);
    if(table)
        free(table);
}