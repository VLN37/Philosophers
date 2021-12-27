CC			= gcc -g3 -pthread
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I../philo/

create:
	$(CC) $(CFLAGS) create.c $(INCLUDES) && ./a.out

variables:
	$(CC) $(CFLAGS) variables.c $(INCLUDES) && ./a.out

mutex:
	$(CC) $(CFLAGS) mutex.c $(INCLUDES) && ./a.out

pthread_loops:
	$(CC) $(CFLAGS) pthread_loops.c $(INCLUDES) && ./a.out

arguments:
	$(CC) $(CFLAGS) arguments.c $(INCLUDES) && ./a.out

semaphore:
	$(CC) $(CFLAGS) semaphore.c $(INCLUDES) && ./a.out
