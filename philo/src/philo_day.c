/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_day.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:44:36 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 15:06:17 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_sleep(t_philo *philos)
{
	glados_speak("is sleeping", philos, philos->id);
	ft_usleep(philos->time_to_sleep);
}

void	ft_think(t_philo *philos)
{
	glados_speak("is thinking", philos, philos->id);
}

void	ft_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->right_fork);
	glados_speak("has taken a fork", philos, philos->id);
	if (philos->number_of_philosopher == 1)
	{
		ft_usleep(philos->time_to_die);
		pthread_mutex_unlock(philos->right_fork);
		return ;
	}
	pthread_mutex_lock(philos->left_fork);
	glados_speak("has taken a fork", philos, philos->id);
	philos->is_eating = 1;
	glados_speak("is eating", philos, philos->id);
	pthread_mutex_lock(philos->meal_lock);
	philos->last_meal = get_time();
	philos->meals_eaten++;
	pthread_mutex_unlock(philos->meal_lock);
	ft_usleep(philos->time_to_eat);
	philos->is_eating = 0;
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
}