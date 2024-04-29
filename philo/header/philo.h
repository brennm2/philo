/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:28:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/29 16:55:48 by bde-souz         ###   ########.fr       */
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

typedef struct	s_data
{
	int				number_of_philosopher;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
}						t_data;

typedef struct s_philo
{
	pthread_t	thread;
	struct	s_data *data;
	
}						t_philo;





//  struct timeval {
//                time_t      tv_sec;     /* seconds */
//                suseconds_t tv_usec;    /* microseconds */
//            };

// SRC/UTILS/ARG_UTILS
int	ft_atoi(const char *str);
int	check_for_int(char **av);
int	check_args(char **av);

#endif