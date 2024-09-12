/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:35:13 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/12 08:41:38 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


int main (int ac, char **av)
{
    (void)av;
    t_table *table;
    
    table = malloc(sizeof(t_table));
    if(!table)
        return(-1);
    if(ac != 5 && ac != 6)
    {
        printf(" The number of characters is wrong \n");
        return(5); // exit clearly
    }
    if(parsing(ac,av,table) != 0)
         return(-1); // exit clearly
    printf("nice parsing\n");
    printf("%d ,%d ,%d ,%d\n",table->nb_philo,table->time_to_die,table->time_to_eat,table->time_to_sleep);
    return(0);
}