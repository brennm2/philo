/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:23:59 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/29 16:57:06 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_init_philo(int number_of_philosopher, int time_to_die,
	int time_to_eat, int time_to_sleep, t_philo *philo)
{
	philo->data = malloc(sizeof(*(philo->data)));
	if (number_of_philosopher < 1 || time_to_die < 0 || time_to_eat < 0 || 
		time_to_sleep < 0)
		{
			printf("\nProblem with number on the arguments\n\n");
			return ;
		}
	philo->data->number_of_philosopher = number_of_philosopher;
	philo->data->time_to_die = time_to_die;
	philo->data->time_to_eat = time_to_eat;
	philo->data->time_to_sleep = time_to_sleep;
	printf("Number of Philos: %d\n", philo->data->number_of_philosopher);
	printf("Time to die: %ld\n", philo->data->time_to_die);
	printf("Time to eat: %ld\n", philo->data->time_to_eat);
	printf("Time to sleep: %ld\n", philo->data->time_to_sleep);
}



int main(int ac, char **av)
{
	t_philo	philo;
	
	if (ac < 5 || ac > 6)
		return(write(1, "\nYou need 4 or 5 arguments!\n\n", 30), 1);
	if(check_args(av))
			return (1);
	ft_init_philo(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), &philo);
}


