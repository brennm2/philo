<div align="center">
  <h1>What is this all about?</h1>
</div>

<p>The Dining Philosophers Problem is a classic computing challenge that illustrates the problems of synchronization and resource management in shared systems, but with a little twist on <b>42 STYLE</b>. It involves <em>N</em> number of philosophers sitting at a round table, 
alternating between eating, sleeping and thinking. 

<p>Each philosopher needs two forks to eat, but if everyone takes the fork to their left simultaneously, a deadlock can occur, since no philosopher can eat without the fork to their right. 
Solutions to this problem aim to avoid deadlocks by ensuring that philosophers share forks in a coordinated way, usually using semaphores or mutexes to control access to resources.
<br>
<br>


<br>
<div align="center">


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

<div align="center">
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

Let's assume you already know what deadlock is and how to find it with `-fsanitize=thread` (If you don't, try asking the friend next to you ;) )<br>

Then you run the program with the fsanitize flag end... Oh no, deadlocks. I'll tell you how I solved my problem with that.<br>

The funny thing is that it was actually <i>"easy"</i> to solve. My problem was that all the philosophers were trying to take the same fork at the same time, which obviously caused a deadlock.<br>
What I did to solve it was, <b>IF</b> the philosopher is <b>even</b>, he takes the fork on the `RIGHT` and then takes the one on the `LEFT`.<br>
And if it's <b>odd</b>, it takes the one on the `LEFT` and then the one on the `RIGHT`.

<div align="center">
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


<br>
<p>Getting caught:</p>
<div align="center">
  <img src="https://i.imgur.com/JFpW2zX.gif">
</div>
<br>
<br>
<p>And, the end of the game:</p>
<div align="center">
  <img src="https://i.imgur.com/OyLdAFl.gif">
</div>
</div>
<br>
<br>
<div align="center">
<h3>--------- The HUD ---------</h3>
</div>
<br>
<p>The game's HUD has 2 states, 1 - POLICE ASSAULT and 2 - POINT OF NO RETURN.</p>
<p>The first state indicates that the player has to collect the money bags and shows the total movement.<br>
The second state indicates that the player has collected all the money bags and needs to leave the map.</p>
<p>I had a problem with the HUD, as the map can be completely modular, so the size of the window also changes, and you have to re-calculate to place it in the right pixel. So, depending on the size of the map, the HUD won't be perfectly centered on the screen.</p>
<br>
<br>
<div align="center">
  <img src="https://i.imgur.com/6XXhyzi.gif">
</div>
<br>
<br>
<div align="center">
<h3>--------- The Map ---------</h3>
</div>
<br>
<p>The map can be modified, altered or even created in a simple and functional way, as long as it follows these rules:</p>

```bash
- Only have ONE Player (P)
- Only have ONE Exit (E)
- There has to be AT LEAST one Collectible (C)
- It has to be enclosed by Walls (1)
- And it needs to be filled with floors (0)
- You can place enemies (X)
- It has to be rectangular
- The player must find a way to collect all the collectibles and reach the exit
- The map can only use the following characters: 1, 0, E, P, C and X(This will not work if you run the base game)
- The map extension must be ".ber"
```
<br>
<br>
<p>Here's a simple example:</p>

```bash
11111111111
1000E0CX001
1000P00C001
10011111001
1X0CX0X0011
1000C000001
10011111001
100C0000001
1000C000X01
11111111111
```
<br>
<br>
<div align="center">
<h3>--------- 42 Rules ---------</h3>
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
<h3>--------- Credits ---------</h3>
</div>


* [Wall and floor Texture](https://o-lobster.itch.io/simple-dungeon-crawler-16x16-pixel-pack)
* [Dallas Texture](https://imgur.com/gallery/Yn21yY8)
* [Cloaker Texture](https://www.pixilart.com/art/pay-day-2-cloaker-ef4aab634260c70?ft=tags&ft_id=)
* [Money Bag Texture](https://www.vecteezy.com/vector-art/5146414-money-bag-pixel-art)
* [Manhole Texture](https://www.vecteezy.com/vector-art/23876320-sewer-drainage-grate-game-pixel-art-vector-illustration)
* All my friends who helped me do this project
