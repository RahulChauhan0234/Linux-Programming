#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
/* create the message buffer */
struct message_buff
	{
	   long int type;
	   char message[100];	

	}msg;
void main()
{
	/* create the message id*/
	int msg_id;
	msg_id=msgget((key_t)1234, 0666 | IPC_CREAT);
	/*receive the message */
	msgrcv(msg_id,&msg,sizeof(msg),1,0);
	printf("Received Message:%s",msg.message);
}
