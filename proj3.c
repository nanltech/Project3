//project3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

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
	pthread_t thread_id;
	printf("before thread\n");
	pthread_create(&thread_id, NULL,dict, NULL);
	pthread_join(thread_id, NULL);
	printf("after thread\n"); 
	return 0;
}






















