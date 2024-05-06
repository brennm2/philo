/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:01:29 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/06 10:44:52 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_check_is_dead(t_philo *philos)
{
	pthread_mutex_lock(philos->dead_lock);
	if (philos->dead == 1);
		return (pthread_mutex_unlock(philos->dead_lock), 1);
	pthread_mutex_unlock(philos->dead_lock);
	return (0);
}

void	*ft_philo_day(void *philos)
{
	t_philo	*temp_philos;

	temp_philos = philos;
	if(temp_philos->id % 2 == 0)
		ft_usleep(1);
	while(ft_check_is_dead(temp_philos) != 1)
	{
		//ft_eat(temp_philos);
		//ft_sleep(temp_philos);
		//ft_think(temp_philos);
	}
	return (philos);
}




int	create_thread(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	glados;
	int 		i;

	i = 0;
	if (pthread_create(&glados, NULL, &ft_wakeup_glados, data->philos) != 0) // Glados ira olhar os philos
		ft_clear_all(ERROR_THREAD_GLADOS, data, forks);
	while (i < data->philos->number_of_philosopher) // Cria threads para cada philo
	{
		if (pthread_create(&data->philos[i].thread, NULL, &ft_philo_day, &data->philos[i]) != 0)
			ft_clear_all(ERROR_THREAD_PHILOS, data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(glados, NULL) != 0)
		ft_clear_all(ERROR_JOIN_GLADOS, data, forks);
	while (i < data->philos->number_of_philosopher)
	{
		if(pthread_join(data->philos[i].thread, NULL) != 0)
			ft_clear_all(ERROR_JOIN_PHILOS, data, forks);
		i++;
	}
	return (0);
}
