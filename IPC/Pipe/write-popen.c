/*
 ============================================================================
 Program Name 	: write-popen.c
 Author       	: Rahul Chauhan
 Topic		: IPC Pipe
 Description	: sending Output to an externel Program
 ============================================================================
 */

#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define BUFSIZE 1024
void main()
{
	/* file descripter */
	FILE *fd_write;


	/*buffer declaration*/
	char buffer[BUFSIZE];
	memset(buffer,'\0',sizeof(buffer));
	sprintf(buffer,"I am Rahul Chauahn");

	/*popen() call*/
	fd_write=popen("grep Rah","w");
	fwrite(buffer,sizeof(char),strlen(buffer),fd_write);
	
	/*pclose() call*/
	pclose(fd_write);


}
