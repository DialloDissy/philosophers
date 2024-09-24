/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:19:38 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/23 23:44:37 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void wait_all_thread(size_t time)
{
	while(get_the_time() < time)
		continue;
}

size_t	get_the_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}



void ft_usleep(size_t time, t_table *table)
{
	t_data_time data;

	data.start = get_the_time();
	data.remaining = time;
	while(data.remaining > 0)
	{
		if(dinner_finish(table))
				break;
		data.now = get_the_time();
		if(data.start + time > data.now)
			data.remaining = data.start + time - data.now;
		else
			data.remaining= 0;
		if(data.remaining > 500)
			data.sleep_time = 500;
		else
			data.sleep_time = data.remaining;
		usleep(data.sleep_time);
		data.now = get_the_time();
		if(data.start + time > data.now)
			data.remaining = data.start +time - data.now;
		else
			data.remaining = 0;
	}		
}
