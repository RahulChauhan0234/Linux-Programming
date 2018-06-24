/* write write a multithreaded program
** where the first thread prints are an odd no.
** second thread prints are an even no. alternatively
*/
#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
pthread_mutex_t mutex;

int count=0;
void *print_even_number()
{
	pthread_mutex_lock(&mutex);
	while(count<20)
	{
		if(count %2 ==0)
		{
			printf("even:%d\n",count);
			count++;
		}
		else
		{
			pthread_mutex_unlock(&mutex);
		}
	}
}
void *print_odd_number()
{
	pthread_mutex_lock(&mutex);
	while(count<20)
	{
		if(count %2 !=0)
		{
        		printf("odd:%d\n",count);
			count++;
		}
		else
		{
			pthread_mutex_unlock(&mutex);
		}
	}
}

void main()
{
	pthread_t even_number_thread,odd_number_thread;
	int result;
	result=pthread_create(&even_number_thread,NULL,print_even_number,NULL);
	result=pthread_create(&odd_number_thread,NULL,print_odd_number,NULL);
	if(result<0)
		printf("thread creation failed");
	pthread_join(even_number_thread,NULL);
	pthread_join(odd_number_thread,NULL);
}
