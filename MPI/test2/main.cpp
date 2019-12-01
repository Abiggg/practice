#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

int fun(void *argv)
{
	int num = *((int*)argv); 
    printf("hello world[%d]\r\n",num);
	return num;
}

int main(int argc, char* argv[])
{
	int ret;
	int i;
	long int count = strtol(argv[1], NULL, 10);
    int* ret_pth = new int(count);
    pthread_t* thread_handler = new pthread_t[count];

	for (i=0; i<count; i++) {
		ret = pthread_create(&thread_handler[i], NULL, (void*)fun, (void*)&count);
	    if (ret < 0) {
	        printf("pthread_creat error[%d]\r\n",ret);
	   }
	}

	printf("pthread finish\r\n");

	for (i=0; i<count; i++) {
		ret = pthread_join(&thread_handler[i], (void**)&ret_pth);
		if (ret < 0) {
			printf("pthread_join error[%d]\r\n", ret);
		} else {
			printf("pthread_join return[%d]\r\n", ret_pth[i]);
		}
	}
	
    printf("hello world\r\n");
	return 0;
}
