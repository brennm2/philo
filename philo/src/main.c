/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:23:59 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/03 09:53:30 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_init_data(char **av, t_philo *philos, t_data *data)
{
	// if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
	// 	|| ft_atoi(av[4]) < 0)
	// {
	// 	write(2, ERROR_ARGS, 44);
	// 	return (1);
	// }
	data->is_dead = 0;
	data->philos = philos;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);


}

void	ft_init_forks(pthread_mutex_t *forks, int number)
{
	int i;

	i = 0;
	while(i < number)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	ft_init_philos_suport(t_philo *philos, char **av, int i)
{
	philos[i].number_of_philosopher = ft_atoi(av[1]);
	philos[i].time_to_die = ft_atoi(av[2]);
	philos[i].time_to_eat = ft_atoi(av[3]);
	philos[i].time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philos[i].meals_number = ft_atoi(av[5]);
	else
		philos[i].meals_number = -1;
}

void	ft_init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].dead = 0;
		ft_init_philos_suport(philos, av, i);
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		philos[i].left_fork = &forks[i];
		if(ft_atoi(av[1]) == 0)
			philos[i].right_fork = &forks[ft_atoi(av[1]) - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
		
	}
}

int	main(int ac, char **av)
{
	t_philo		philos[200];
	t_data		data;
	pthread_mutex_t	forks[200];
	
	if (ac < 5 || ac > 6)
		return (write(1, "\nYou need 4 or 5 arguments!\n\n", 30), 1);
	if(check_args(av))
		return (1);
	ft_init_data(av, philos, &data);
	ft_init_forks(forks, ft_atoi(av[1]));
	ft_init_philos(philos, &data, forks, av);
	//if (init_alloc(&data, philo))
	//	return (1);
	
	
	// init_data(data, )
}


