<div align="center">
  <h1>What is this all about?</h1>
</div>

<p>The Dining Philosophers Problem is a classic computing challenge that illustrates the problems of synchronization and resource management in shared systems, but with a little twist on <b>42 STYLE</b>. It involves <em>N</em> number of philosophers sitting at a round table, 
alternating between eating, sleeping and thinking. 

<p>Each philosopher needs two forks to eat, but if everyone takes the fork to their left simultaneously, a deadlock can occur, since no philosopher can eat without the fork to their right. 
Solutions to this problem aim to avoid deadlocks by ensuring that philosophers share forks in a coordinated way, usually using semaphores or mutexes to control access to resources.
<div align="center">
  <img src="https://i.imgur.com/tYvu8RJ.png">
</div>

<br>

<div align="center">
  <h1>How can I test it?</h1>
</div>
<div align="center">
<p>I'm glad you asked! The process is very simple.</p>
</div>

<br>
<h4>1º Step - Download the files:</h4>

```bash
git clone https://github.com/brennm2/philo.git && cd philo
```

<h4>2º Step - Compiling the program</h4>

```bash
cd philo
make
```
<br>
<h4>3º Step - Running the program!</h4>

Now you need to put in the following inputs:<br>
```bash
./philo NUMBER_OF_PHILO TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP
```
`NUMBER_OF_PHILO` = Number of philosophers that is sitting on the table<br>
`TIME_TO_DIE` = Time, in milliseconds, that philosophers can die<br>
`TIME_TO_EAT` = Time, in milliseconds, that philosophers can eat<br>
`TIME_TO_SLEEP` = Time, in milliseconds, that philosophers can sleep<br>
`NUMBER_OF_MEALS` = How many meals that all philosophers have to eat to end the program (this one is optional)<br>

Here is an example:
<br>

```bash
./philo 5 800 200 200
```

or, if you want to set a limit of meals
```bash
./philo 5 800 200 200 5
```
<br>

<br>
<div align="center">
  <img src="https://i.imgur.com/dYMMSHf.gif">
</div><br>

<div align="center">
  <h1>Considerations and Explanations</h1>
</div>
<div align="center">
<h3>--------- Soft Locking when sleeping ---------</h3><br>
</div>

Sometimes, if you set the sleep value too high, the program can get stuck in a state and not finish.<br>
 For example `5 800 200 200000`<br>
<p>Then you ask yourself, "How can this happen?", well... <br>

The problem is that one philosopher dies, because enough time has passed for him to die, but another philosopher keeps sleeping for `200000ms`. This causes a soft lock in the program, and it doesn't finish, since one philosopher has died.

Example and solution (on details):
</p>
<details>
<div align="center">
  <img src="https://i.imgur.com/XR534rW.gif">
</div>
<br>

Well, the solution is a simple one, when you run your custom `usleep` function, you have to check if someone has died.<br>
<p>I did like this:
  
```bash
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
```
</details>

<div align="center">
<h3>--------- MY deadlock with forks ---------</h3><br>
</div>

Let's assume you already know what deadlock is and how to find it with `-fsanitize=thread` (If you don't, try asking the friend next to you ;) )
Then you run the program with the fsanitize flag end... Oh no, deadlocks. I'll tell you how I solved my problem with that.<br>

The funny thing is that it was actually <i>"easy"</i> to solve. My problem was that all the philosophers were trying to take the same fork at the same time, which obviously caused a deadlock.<br>

What I did to solve it was, <b>IF</b> the philosopher is <b>even</b>, he takes the fork on the `RIGHT` and then takes the one on the `LEFT`.<br>
And if it's <b>odd</b>, it takes the one on the `LEFT` and then the one on the `RIGHT`.

Example and solution (on details):
</p>
<details>
<div align="center">
  <img src="https://i.imgur.com/s715te4.gif">
</div>
<br>

Here how I did it (Keep in mind, fsanitize can break your timings):<br>
  
```bash
if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		glados_speak(C_CYAN"has taken a fork"END_COLOR, philos, philos->id);
		pthread_mutex_lock(philos->left_fork);
	}
	else
	{
		pthread_mutex_lock(philos->left_fork);
		glados_speak(C_CYAN"has taken a fork"END_COLOR, philos, philos->id);
		pthread_mutex_lock(philos->right_fork);
	}
```
</details>

<div align="center">
<h3>--------- Low sleep time and odd number ---------</h3><br>
</div>

If you used my solution for deadlocks (or a similar one), now your philosophers can die randomly if the number of philosophers is odd and the sleeping time is short, for example `./philo 5 800 200 100`
<p>Then, again, you ask yourself, "WHATT?", well... <br>

It's OK, we can fix it. Again, the problem is with the odd numbers. So, to fix it, we need to set a condition on the `ft_think` function.<br>

Example and solution (on details):
<details>
<br>

We need to find the right time for the philosopher, if necessary, to think. We can do this: `(time to eat * 2) - time to sleep`<br>
You can do like this:

```bash
if (philos->number_of_philosopher % 2 != 0)
		ft_usleep((philos->time_to_eat * 2) - philos->time_to_sleep, philos)
```
</details>

<div align="center">
<h3>--------- Philosophers stealing food ---------</h3><br>
</div>

Sometimes, a philosopher can die randomly, and this can be caused by one of the philosophers “stealing” the turn of another who is waiting.<br>

For example: `Philo 1` has just eaten and is going to sleep. `Philo 3` is waiting for someone to release the forks so he can eat. Then `Philo 1` wakes up and grabs the forks before `Philo 3`, who ends up dying.<br>

The solution is quite simple. Just set the `ft_usleep` function to 1ms in the `ft_think` function. This would be `ft_usleep(1)`. This gives `Philo 3` enough time to pick up the forks and leave `Philo 1` to think.
<br>
<br>
<div align="center">
<h1> 42 Rules </h1>
</div>
<br>
<p>In every project we must follow certain rules, here are the rules for this project:</p>

```bash
- The project must not have memory leaks
- The project must use the flags -Wall -Wextra -Werror
- Each function can have a maximum of 25 lines
- Each file should only have 5 functions
- We should keep the code as clean as possible, for example, declarations should be on separate lines
- We cannot use "for", "do...while", "switch", "case", "goto", ternary operators, or variable-length arrays
```

<br>
<br>
<div align="center">
<h1> Credits </h1>
</div>


* [Philosophers 42 Guide](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)
* [Philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
* [Pthreads in C - Playlist (CodeVault)](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
* All my friends who helped me do this project
