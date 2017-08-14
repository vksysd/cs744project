// Pthread Creation and Termination Example
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREADS 5

void *PrintHello(void *threadid){
  long tid;
  tid = (long)threadid;
  printf("Hello world! It's me, thread #%ld!\n",tid );
  pthread_exit(NULL);
}

int main(int argc, int *argv[]){
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0;t<NUM_THREADS;t++){
    printf("In main: creating thread %ld\n", t);
    rc =pthread_create(&threads[t],NULL,PrintHello,(void *)t);
    if(rc){
      printf("Error; return code from pthread_create()%d \n",rc );
      exit(-1);
    }
  }
  pthread_exit(NULL);
}