/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:35:36 by sidiallo          #+#    #+#             */
/*   Updated: 2024/09/24 23:32:30 by sidiallo         ###   ########.fr       */
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



# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */




typedef enum s_msg
{
	EAT,
	SLEEP,
	THINK,
	DIED,
	FORK,
}	t_msg;


typedef struct s_data_time
{
	size_t start;
	size_t remaining;
	size_t now;
	size_t sleep_time;
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
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	count_meal_mtx;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	last_meal_mtx;
	int				is_dead;
	int				*is_finish;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				nb_meal;
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
void				*monitor(void *arg);
int					dinner_finish(t_table *table);
void				print_msg(t_philo *philo, int msg);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				ft_usleep(size_t time, t_table *table);
void				set_death(t_table *table);
int					check_death(t_philo *philo);
int					handle_end(t_table *table);

#endif