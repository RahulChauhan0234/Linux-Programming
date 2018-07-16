#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
struct msg_buff{
	long int type;
	char message[100];
}msg;
void main()
{

	/*craete message Queue */
	int msg_id;
	msg_id=msgget((key_t)1234,0666|IPC_CREAT);
	msg.type=1;	
	printf("enter the message:");
	scanf("%s",msg.message);
	/* send messgae */
	msgsnd(msg_id,&msg,sizeof(msg),0);	
	printf("data sent:%s",msg.message);
}


