#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#define SIZE_BUF 1024
void main()
{
	/* create the shared memory */
	int shm_reader_id;
	shm_reader_id=shmget((key_t)1234,SIZE_BUF, 0666|IPC_CREAT);
	/* attached the shared memory */
	void* shared_memory_reader;
	shared_memory_reader=shmat(shm_reader_id,(void*)0,0);
	/* perform the operation */
	printf("%s",shared_memory_reader);
	/* delete the shared memory */
	shmdt(shared_memory_reader);
	shmctl(shm_reader_id,IPC_RMID,NULL);


}

