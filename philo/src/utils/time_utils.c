#include "../../header/philo.h"


void	ft_usleep(size_t milsecond)
{
	size_t	start_time;

	start_time = get_time();
	while((get_time() - start_time) < milsecond)
		usleep(500);
}

size_t	get_time(void)
{
	struct timeval time;

	if(gettimeofday(&time, NULL) == -1)
		write(2, "ERROR! Failed to use gettimeofday\n", 34);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}