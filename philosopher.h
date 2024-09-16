/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:35:36 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/16 21:43:29 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>


typedef enum s_msg
{
	EAT,
	SLEEP,
	THINK,
	DIED,
}	t_msg;


typedef struct s_data_time
{
	int start;
	int remaining;
} t_data_time;



typedef	struct s_table t_table;


typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				last_meal;
	int				count_meal;
	t_table			*table;

}					t_philo;

typedef struct s_table
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	count_meal_mtx;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	last_meal_mtx;
	int				*is_dead;
	int				*is_finish;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				nb_meal_max;
	int				nb_philo;
	int				time_start;
}					t_table;



int					parsing(int ac, char **av, t_table *table);
int					check_digit(char **av);
int					check_limit(char **av);
int					ft_isdigit(int c);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
long long			ft_atol(const char *nptr);
int					init_table(t_table *table);
size_t				get_the_time(void);
int					dinner(t_table *table);
void				wait_all_thread(size_t time);
void				exit_philo(t_table *table);

#endif