#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define BUF_SIZE 1024

void main()
{
	/*create the shared memory */
	int shm_id;
	shm_id=shmget((key_t)1234,BUF_SIZE,0666|IPC_CREAT);
	if(shm_id < 0)
		printf("shared memory creation faild");
	/* attached the shared memory */
	void* shared_memory;
	shared_memory=shmat(shm_id,(void*)0,0);
	/* operation on shared memroy */
	printf("write data on shared memory");
	scanf("%s",(char*)shared_memory);
	printf("you entered:%s",shared_memory);
	/* detached the shared memory */
	shmdt(shared_memory);



}

