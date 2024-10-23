#include <stdio.h>
#include <stdlib.h>
#include "mythreads.h"

#define SIZE 1250

static int array[SIZE] = {0};
pthread_mutex_t locks[SIZE];

// add any global declarations here


// return a random index
unsigned int get_idx() {
  return(random()%(SIZE));
}

void *array_update(void *args) {
  print_thread_info();
  // fill in your the solution here to update the array 10000 times.
  // do not remove or modify any other lines of code in this function
  
  for (int i = 0; i < 10000; i++) {
    int new_integer = get_idx();
    Pthread_mutex_lock(&locks[new_integer]);
    array[new_integer]++;
    Pthread_mutex_unlock(&locks[new_integer]);
  }


  printf("%ld done\n",Thread_gettid());
  return NULL;
}

int main (int argc, char **argv)
{
  pthread_t threads[4];
  
  srandom(2001); // seed the random number generator
  my_threads_init();

  // fill in this portion to initialize locks and create 4 threads 
  // main should use join to wait for all four threads to finish before executing the finish up code

  for (int i = 0; i < SIZE; i++) {
      Pthread_mutex_init(&locks[i], NULL);
    }

    Pthread_create(&threads[0], NULL, array_update, NULL);
    Pthread_create(&threads[1], NULL, array_update, NULL);
    Pthread_create(&threads[2], NULL, array_update, NULL);
    Pthread_create(&threads[3], NULL, array_update, NULL);

    for (int i = 0; i < 4; i++) {
      Pthread_join(threads[i], NULL);
    }


  my_threads_end();
  // main finish up code.
  int sum = 0;
  for (int i =0; i < SIZE; i++) {
    if (array[i]) {
      printf("%d: %d\n",i,array[i]);
      sum += array[i];
    }
  }
  printf("main: result %d\n",sum);

  return(0);
}
