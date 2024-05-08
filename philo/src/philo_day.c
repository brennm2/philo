/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_day.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:44:36 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 15:26:32 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_sleep(t_philo *philos)
{
	glados_speak("is sleeping", philos, philos->id);
	ft_usleep(philos->time_to_sleep, philos);
}

void	ft_think(t_philo *philos)
{
	glados_speak(C_MAGENTA"is thinking"END_COLOR, philos, philos->id);
	if (philos->number_of_philosopher % 2 != 0)
	{
		ft_usleep((philos->time_to_eat * 2) - philos->time_to_sleep, philos);
	}
	else
		ft_usleep(1, philos);
}

void	ft_one_philo(t_philo *philos)
{
	pthread_mutex_lock(philos->right_fork);
	glados_speak(C_CYAN"has taken a fork"END_COLOR, philos, philos->id);
	ft_usleep(philos->time_to_die, philos);
	pthread_mutex_unlock(philos->right_fork);
}

void	ft_eat(t_philo *philos)
{
	if (philos->number_of_philosopher == 1)
		return (ft_one_philo(philos));
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		glados_speak(C_CYAN"has taken a fork"END_COLOR, philos, philos->id);
		pthread_mutex_lock(philos->left_fork);
	}
	else
	{
		pthread_mutex_lock(philos->left_fork);
		glados_speak(C_CYAN"has taken a fork"END_COLOR, philos, philos->id);
		pthread_mutex_lock(philos->right_fork);
	}
	glados_speak(C_CYAN"has taken a fork"END_COLOR, philos, philos->id);
	philos->is_eating = 1;
	pthread_mutex_lock(philos->meal_lock);
	glados_speak(C_YELLOW"is eating"END_COLOR, philos, philos->id);
	philos->last_meal = get_time();
	philos->meals_eaten++;
	pthread_mutex_unlock(philos->meal_lock);
	ft_usleep(philos->time_to_eat, philos);
	philos->is_eating = 0;
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
}
