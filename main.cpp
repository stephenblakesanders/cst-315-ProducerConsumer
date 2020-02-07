#include <iostream>
#include <cstdlib>
#include <pthread.h>

// Stephen Blake Sanders
/***

The approach to implementation was to simply create a string of
processes and identify them individually. This basic approach
allowed me to create any amount of processes and keep them
individually identified and distinguished from each other.
Because of this, I was able to create two processes and identify
one of them as the Producer process and the other as the Consumer
process. Because of identifying the processes, I am able to manage
the processes and threads post creation.

***/

using namespace std;

//defines the amount of threads to be printed, could easily increase
#define NUM_THREADS 2

// prints which thread, producer or consumer and the thread ID
void *PrintHello(void *threadid) {
// capture thread id
   long tid;
   tid = (long)threadid;

// determines if thread is producer or consumer based by ID,
// in this case producer is thread 1 and consumer is thread 0
   if (tid == 0)
   {
        cout << "Hello World, from Consumer thread! Thread ID, " << tid << endl;
   }
   else
   {
        cout << "Hello World, from Producer thread! Thread ID, " << tid << endl;
   }
   pthread_exit(NULL);
}


// main running function
int main () {
// creates threads based on definition of NUM_THREADS at the top of the program
   pthread_t threads[NUM_THREADS];

// declaring integers for use in for loop
   int rc;
   int i;

// for loop, runs to print the current running thread and then initializes
// the thread for the print function above
   for( i = 0; i < NUM_THREADS; i++ ) {
    // prints the current thread before creation
      cout << "main() : creating thread, " << i << endl;
    // initializes thread and calls printHello function above
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

    // catches errors, prints if threads are unable to be created
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
