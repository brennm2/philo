/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:42:25 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/29 14:44:08 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int	check_for_int(char **av)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (av[i])
	{
		if (av[i][x] == '\0')
			return (1);
		while (av[i][x])
		{
			if (!(av[i][x] >= '0' && av[i][x] <= '9'))
				return (1);
			x++;
		}
		x = 0;
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	if (check_for_int(av))
		return (write(2, "Error! You have a problem with args!\n", 37), 1);
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) <= 0)
		return (write(2, "Error! You have problem with philosophers!\n", 43),
			1);
	if (ft_atoi(av[2]) <= 0)
		return (write(2, "Error! You have problem with time to die!\n", 43), 1);
	if (ft_atoi(av[3]) <= 0)
		return (write(2, "Error! You have problem with time to eat!\n", 43), 1);
	if (ft_atoi(av[4]) <= 0)
		return (write(2, "Error! You have problem with sleep time!\n", 42), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0))
		return (write(2, "Error! Problem with number of times to loop\n", 45),
			1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sinal;
	int	number;

	i = 0;
	sinal = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal = sinal * -1;
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10;
		number = number + str[i] - '0';
		i++;
	}
	return (number = number * sinal);
}
