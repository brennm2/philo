// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   free_exit.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/30 11:56:46 by bde-souz          #+#    #+#             */
// /*   Updated: 2024/04/30 15:32:18 by bde-souz         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../header/philo.h"

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


// int	ft_error(char *str, t_data *data, int flag)
// {
// 	printf("%s\n", str);
// 	if (data)
// 		ft_free(data, flag);
// 	return (1);
// }