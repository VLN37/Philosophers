# Philosophers

The 9th project in 42 cursus and a [classical problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) that introduces us to multi-threading applications.

The mandatory part asks us to create each philosopher as threads and forks as mutexes. Each philosopher only uses the forks in each of their sides.


The bonus part asks us to create each philosopher as a process and forks as semaphores. Forks are all in the middle of the tabke and philosophers can take any of them.

---

### My badge

![philobadge](docs/philosophersm.png)

### My grade

![philograde](docs/philosophersgrade.png)

---

### How does it work?

A number of philosophers sit at a circular table, they have a fork in each side that they share with the philosophers beside them. Each philosopher is a thread / process, each fork is a mutex / semaphore.

Serving and eating spaghetti with a single fork is very inconvenient so the philosophers will eat with two forks, one for each hand. When they finish eating they sleep, and when they finish sleeping they think. They have a limited time to start eating again, otherwise they die.

### Available functions

To solve the initial challenge you we are allowed to use a only a few functions from ``pthread library``. Namely:

- [pthread_create](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [pthread_detach](https://man7.org/linux/man-pages/man3/pthread_detach.3.html)
- [pthread_join](https://man7.org/linux/man-pages/man3/pthread_join.3.html)
- [pthread_mutex_init](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html)
- [pthread_mutex_destroy](https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html)
- [pthread_mutex_lock](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [pthread_mutex_unlock](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)

### Parameters

- time_to_die - the time in which they die if they have not started eating again
- time_to_eat - how long they take to eat, time in which they must hold both forks
- time_to_sleep - how long do they spend sleeping
- number_of_meals - how many times do they eat before the simulation stops (optional)

### Requisites

- Every philosopher should eat and never starve
- Maximum 10ms between the death of a philosopher and a timestamp that they have died
- Philosophers do not speak with each other
- Philosophers do not know when the other is about to die
- Philosophers should avoid dying! (duh)

---

### What i learned?

By observing how long your implementation takes to perform and report the tasks you start to grasp the concepts of concurrency and parallelism. Also how threads share memory differently than processes within the same program.

Concurrency means the tasks are being performed side-by-side but not necessarily at the same instant. For example, only one thread may modify a shared variable at any one time with no chance of error. Parallelism means the tasks are being performed literally at the same time.

Since the rules are pretty strict you'll soon realize you need to be careful with what can and what cannot be performed in parallel. The cleaner your architecture the more work can be performed in tandem.

---

## How to use

``` bash

# clone the repository
git clone https://github.com/VLN37/Philosophers.git philosophers && cd philosophers

# compile the mandatory program with:
make

# run the program
./bin/philo [philo quantity] [time_to_die] [meal_time] [sleep_time] [num of meals]

#for example
./bin/philo 4 410 200 200 5

#wonder about the ephemerity of life while philosophers perform their mundane routines

#clean the repository with
make fclean

#Well Done!
```

---
## Updating

This project is regularly updated with code maintenance and bug fixes

---

## License

This project is licensed under the MIT terms [available here](LICENSE)
