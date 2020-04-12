//project3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define Wordsize 35
typedef char string[Wordsize];



void *dict(void *vargp)
{
	sleep(1);
	printf("hello world22\n");
	pthread_t thread_id;
        printf("before thread222\n");
        pthread_create(&thread_id, NULL,dict, NULL);
        //pthread_join(thread_id, NULL);
        printf("after thread22\n");
	return NULL;

}

int main(int argc, char *argv[])
{
	printf("hello world\n");	
	string dictionary[99172];
	printf("goodbye world\n");
	FILE *fp;
	printf("SALT\n");
	fp = fopen("/home/TU/tuk93452/repo4/words","r");
	if(fp == NULL)
	{
		perror("Error in opening the file");
		return(-1);
	}
	printf("salmon dinner\n");
	/*for (int i=0; i <5; i++)
	{
		printf("a");
		fscanf(fp,"%s", dictionary[i]);
	}*/

	char *token;
	char line[35];
	const char dlim[2] = " ";
	int u = 0;
	while (!feof(fp))
	 {
		//printf("hello from the other side");
		fgets(line, 150, fp);
		token = strtok(line,dlim);     
    		//token = strtok(NULL,dlim);
		//arr[u]=stringToNum(token);
		dictionary[u] == token;
		//printf("%d\n", arr[u]);
		u++;
	}
	


	fclose(fp);
	printf("dictionary 5555 = %s\n",dictionary[5555]);
	
	pthread_t thread_id;
	printf("before thread\n");
	pthread_create(&thread_id, NULL,dict, NULL);
	pthread_join(thread_id, NULL);
	printf("after thread\n"); 
	return 0;
}






















