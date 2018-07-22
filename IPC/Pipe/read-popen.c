/*
 ============================================================================
 Program Name 	: read-popen.c
 Author       	: Rahul Chauhan
 Topic		: IPC Pipe
 Description	: Reading output from an externel program
 ============================================================================
 */

#include<stdio.h>
#include<unistd.h>

#define BUFSIZE 40
void main()
{
	/* file descripter */
	FILE *fd_read;

	/*buffer declaration*/
	char buffer[BUFSIZE];
	memset(buffer,'\0',sizeof(buffer));
	
	/*popen() call*/
	fd_read=popen("date","r");
	fread(buffer,sizeof(char),BUFSIZE,fd_read);
	printf("%s",buffer);
	
	/*pclose() call*/
	pclose(fd_read);


}
