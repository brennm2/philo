/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:02:36 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 15:45:53 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int	ft_check_sleep(t_philo *philo)
{
	if (*philo->dead == 1)
		return (1);
	return (0);
}

void	ft_usleep(size_t milsecond, t_philo *philo)
{
	size_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < milsecond && ft_check_sleep(philo) == 0)
	{
		usleep(500);
	}
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "ERROR! Failed to use gettimeofday\n", 34);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
