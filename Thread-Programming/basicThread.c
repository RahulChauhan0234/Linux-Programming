#include<stdio.h>
#include<pthread.h>

void *threadFunction()
{
	for(int i=0;i<100;i++)
	printf("thread1");
}


void *threadFunction2()
{
	for(int i=0;i<100;i++)
	printf("thread2\n");
}

void main()
{
 pthread_t thread1,thread2;
 int ret;
	/* create thread */
	ret= pthread_create(&thread1,NULL,&threadFunction,NULL);

	ret= pthread_create(&thread2,NULL,&threadFunction2,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);


}
