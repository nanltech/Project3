//project3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define Wordsize 35
typedef char string[Wordsize];

string dictionary[99172];

void* threadSpool( void *arg)
{
	pthread_t threads[10];
	// one thread should be detached for counting purposes
	for(int i=0; i<10; i++)//create threads
	{
		//pthread_create(&threads[i], NULL, dict, "hello");//error with dict function, doesn't think it exists
	}
	for(int k=0; k<10; k++)//joins threads
        {
                pthread_join(threads[k], NULL);
        }

	return NULL;
} 

int dict(char *word)//searchs dictionary for word
{
	for(int i=0; i<99172; i++)
	{
		if(strcmp(dictionary[i],word)==0)
		{
			printf("match found");
			return 1;
		}	
	}
	return 0;
}

int main(int argc, char *argv[])
{
		
	FILE *fp;
	fp = fopen("/home/TU/tuk93452/repo4/words.txt","r");
	if(fp == NULL)
	{
		perror("Error in opening the file");
		return(-1);
	}

	//copy dictionary file to an array
	char *token;
	char line[35];
	const char dlim[2] = " ";
	int u = 0, n = 1;
	
	while(n>0)
	 {	
		n = fscanf(fp, "%s", dictionary[u]);
		u++;
	}
	fclose(fp);
	
	
	int g = dict("hello's");
	printf(" match = %d\n", g);
	
	int portNumber = 8888;
	int socket_desc, new_socket, c;    
	struct sockaddr_in server, client;
	if (socket_desc == -1){ 
		puts("Error creating socket!");
		exit(1);
	}

	// prepare sockaddr_instructure    
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(portNumber);
	int bind_result = bind(socket_desc, (struct sockaddr*)&server, sizeof(server));
	if (bind_result < 0){
		puts("Error: failed to Bind.");
		exit(1);
	}
	puts("Bind done.");

	listen(socket_desc, 3);
	puts("Waiting for incoming connections...");
	
	while (1){
		c = sizeof(struct sockaddr_in);
		new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);
		if (new_socket < 0){
		    puts("Error: Accept failed");
			continue;
		}

	puts("Connection accepted");
	//create thread with word passed from socket request




	/*
	pthread_t thread_id;
	printf("before thread\n");
	pthread_create(&thread_id, NULL,dict, NULL);
	pthread_join(thread_id, NULL);
	printf("after thread\n");
	*/ 
	return 0;
}






















