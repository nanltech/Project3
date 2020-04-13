//project3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define Wordsize 35
typedef char string[Wordsize];

string dictionary[99172];

int dict(char *word)
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
	/*sleep(1);
	printf("hello world22\n");
	pthread_t thread_id;
        printf("before thread222\n");
        pthread_create(&thread_id, NULL,dict, NULL);
        //pthread_join(thread_id, NULL);
        printf("after thread22\n");
	return NULL;
	*/
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
	//while (!feof(fp))
	while(n>0)
	 {	
		n = fscanf(fp, "%s", dictionary[u]);
		u++;
	}
	fclose(fp);
	
	
	int g = dict("hello's");
	printf(" match = %d\n", g);

	/*
	pthread_t thread_id;
	printf("before thread\n");
	pthread_create(&thread_id, NULL,dict, NULL);
	pthread_join(thread_id, NULL);
	printf("after thread\n");
	*/ 
	return 0;
}






















