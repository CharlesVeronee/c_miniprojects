#include <stdio.h>
#include <stdlib.h>
#include "mythreads.h"


#define SIZE 1000
#define NUM_THREADS 4


static int array[SIZE];

typedef struct {
  unsigned int id;
  unsigned int start;
  unsigned int end;
} args_t;

void print_args(args_t *args) {
  printf("args: id %d start %d end %d\n", args->id, args->start, args->end);
}

void *thread_double(void *argin) {
  // fill in this function to have the thread update its range of array entries
  // each entry in the array should be multiplied by 2.
  // also call print_thread_info

  print_thread_info();
  print_args((args_t *)argin);

  // cast to args_t
  args_t *arguments = (args_t *)argin;

  for (int i = arguments->start; i < arguments->end; i++) {
    array[i] *= 2;
  }

  printf("%ld done\n", Thread_gettid());
  return NULL;

}

int main (int argc, char **argv)
{
  pthread_t threads[4];
  args_t args[4];

  // initialize the global array
  for (int j = 0; j < SIZE; j++) {
    array[j] = j;
  }

  int sum = 0;
  for (int i =0; i < SIZE; i++) {
    sum += array[i];
  }
  printf("main: before %d\n",sum);

  //chop array into 4 parts -> then use pthread create procedure to create thread -> then define own thread routine to sum up array

  // fill in this portion to create 4 threads that operate on 1/4 of the array
  // you need to setup the arg structure appriately
  // main should use join to wait for all four threads to finish before executing the finish up code


  // create threads

  args[0].id = 0;
  args[0].start = 0;
  args[0].end = 250;
  pthread_create(&threads[0], NULL, thread_double, (void *)&args[0]);

  args[1].id = 1;
  args[1].start = 250;
  args[1].end = 500;
  pthread_create(&threads[1], NULL, thread_double, (void *)&args[1]);

  args[2].id = 2;
  args[2].start = 500;
  args[2].end = 750;
  pthread_create(&threads[2], NULL, thread_double, (void *)&args[2]);

  args[3].id = 3;
  args[3].start = 750;
  args[3].end = 1000;
  pthread_create(&threads[3], NULL, thread_double, (void *)&args[3]);


  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
  pthread_join(threads[3], NULL);

 // main finish up code.

  sum = 0;
  for (int i =0; i < SIZE; i++) {
    sum += array[i];
  }
  printf("main: result %d\n",sum);

  return (0);
}
