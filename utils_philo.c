/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:19:38 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/16 21:21:56 by sidiallo         ###   ########.fr       */
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



// int ft_usleep()