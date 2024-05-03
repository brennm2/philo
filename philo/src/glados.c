/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glados.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:35:22 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/03 16:59:29 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	glados_speak(char *str, t_philo *philos, int philo_id)
{
	size_t	time;

	pthread_mutex_lock(&philos->write_lock);
	time = get_time() - philos->start_time;
	if(ft_check_is_dead(philos) == 1)
		printf("%zu %d %s\n", time, philo_id, str);
	pthread_mutex_unlock(&philos->write_lock);
}

int	ft_is_dead(t_philo *philos)
{
	pthread_mutex_lock(philos->meal_lock);
	if(get_time() - philos->last_meal >= philos->time_to_die &&
		philos->is_eating == 0)
	{
		pthread_mutex_unlock(&philos->meal_lock);
		return(1);
	}
	pthread_mutex_unlock(philos->meal_lock);
	return (0);
}

int	ft_find_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while(i < philos->number_of_philosopher)
	{
		if(ft_is_dead(&philos[i]))
		{
			glados_speak("died", philos, philos[i].id);
			pthread_mutex_lock(philos[i].dead_lock);
			philos[i].dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_wakeup_glados(void *philos)
{
	t_philo	*temp_philos;

	temp_philos = (t_philo *)philos;
	while(1)
	{
		if((ft_find_dead(philos) == 1) )//|| (ft_eat_all_meals(philos) == 1))
			break ;
	}
	return (philos);
}