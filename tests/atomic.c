# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <semaphore.h>

_Atomic int acnt;
int cnt;

void	*f(void* thread)
{
	for(int n = 0; n < 1000; ++n)
	{
		++cnt;
		++acnt;
	}
	return (thread);
}

int	main(void)
{
	pthread_t thr[500];
	for(int n = 0; n < 10; ++n)
		pthread_create(&thr[n], NULL, &f, NULL);
	for(int n = 0; n < 10; ++n)
		pthread_join(thr[n], NULL);

	printf("The atomic counter with 10 threads is %u\n", acnt);
	printf("The non-atomic counter with 10 threads is %u\n", cnt);

	cnt = 0;
	acnt = 0;
	for(int n = 0; n < 100; ++n)
		pthread_create(&thr[n], NULL, &f, NULL);
	for(int n = 0; n < 100; ++n)
		pthread_join(thr[n], NULL);

	printf("The atomic counter with 100 threads is %u\n", acnt);
	printf("The non-atomic counter with 100 threads is %u\n", cnt);

	cnt = 0;
	acnt = 0;
	for(int n = 0; n < 500; ++n)
		pthread_create(&thr[n], NULL, &f, NULL);
	for(int n = 0; n < 500; ++n)
		pthread_join(thr[n], NULL);

	printf("The atomic counter with 500 threads is %u\n", acnt);
	printf("The non-atomic counter with 500 threads is %u\n", cnt);
}
