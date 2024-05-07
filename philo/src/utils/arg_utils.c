/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:42:25 by bde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 15:34:25 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
		return (write(2, ERROR_ARGS_INT, ft_strlen(ERROR_ARGS_INT)), 1);
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) < 1)
		return (write(2, ERROR_PHILO, ft_strlen(ERROR_PHILO)), 1);
	if (ft_atoi(av[2]) <= 0)
		return (write(2, ERROR_DIE, ft_strlen(ERROR_DIE)), 1);
	if (ft_atoi(av[3]) <= 0)
		return (write(2, ERROR_EAT, ft_strlen(ERROR_EAT)), 1);
	if (ft_atoi(av[4]) <= 0)
		return (write(2, ERROR_SLEEP, ft_strlen(ERROR_SLEEP)), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0))
		return (write(2, ERROR_MEAL, ft_strlen(ERROR_MEAL)), 1);
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
