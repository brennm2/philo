/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:28:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/30 16:05:45 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdint.h>
# include <pthread.h>
# include <stdint.h>
# include <stdlib.h>

# define ERROR_ALLOC_1 "ERROR! Problem with mallocing thread_id\n"
# define ERROR_ALLOC_2 "ERROR! Problem with mallocing forks\n"
# define ERROR_ALLOC_3 "ERROR! Problem with mallocing philos\n"

# define ERROR_ARGS_INT "ERROR! You have a problem with args!\n"
# define ERROR_ARGS "ERROR! Problem with number on the arguments\n"
# define ERROR_PHILO "ERROR! You have problem with philosophers!\n"
# define ERROR_DIE "ERROR! You have problem with time to die!\n"
# define ERROR_EAT "ERROR! You have problem with time to eat!\n"
# define ERROR_SLEEP "Error! You have problem with sleep time!\n"
# define ERROR_MEAL "Error! Problem with number of times to eat meals\n"


typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					is_eating;
	int					meals_eaten;
	int					meals_number;
	int					number_of_philosopher;
	int					*dead;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;

	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	
}						t_philo;

typedef struct	s_data
{
	int					is_dead;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
	t_philo				*philos;
}						t_data;




//  struct timeval {
//                time_t      tv_sec;     /* seconds */
//                suseconds_t tv_usec;    /* microseconds */
//            };

// SRC/UTILS/ARG_UTILS
int	ft_atoi(const char *str);
int	check_for_int(char **av);
int	check_args(char **av);

// SRC/UTILS/FREE_EXIT
void ft_free(t_data *data, int flag);
int	ft_error(char *str, t_data *data, int flag);

#endif