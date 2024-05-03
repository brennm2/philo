/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:56:46 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/03 11:42:00 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

// void ft_clear_data(t_data *data, int flag)
// {
// 	if (flag == 1)
// 	{
// 		if (data->thread_id)
// 			free(data->thread_id);
// 	}
// 	if (flag == 2)
// 	{
// 		if (data->thread_id)
// 			free(data->thread_id);
// 		if (data->forks)
// 			free(data->forks);
// 	}
// 	if (flag == 3)
// 	{
// 		if (data->thread_id)
// 			free(data->thread_id);
// 		if (data->forks)
// 			free(data->forks);
// 		if (data->philos)
// 			free(data->philos);
// 	}
// }

// void ft_free(t_data *data, int flag)
// {
// 	int i;

// 	i = 0;
// 	while(i < data->number_of_philosopher)
// 	{
// 		if(flag == 1)
// 			break ;
// 		if (flag == 2)
// 			pthread_mutex_destroy(&data->forks[i]);
// 		if (flag == 3)
// 		{
// 			pthread_mutex_destroy(&data->forks[i]);
// 			pthread_mutex_destroy(&data->philos[i].lock);
// 		}
// 		i++;
// 	}
// 	pthread_mutex_destroy(&data->lock);
// 	pthread_mutex_destroy(&data->write);
// 	ft_clear_data(data, flag);
// }


void	ft_clear_all(char *str, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		write(2, str, ft_strlen(str));
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	while(i < data->philos->number_of_philosopher)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}