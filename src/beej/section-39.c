// ******************************************************
// Multi-threading
#include <stdio.h>
#include <threads.h>

int run_in_thread(void *arg)
{
    int *val = arg;

    printf("THREAD: Running thread with arg %d\n", *val);

    return (*val) / 2;
}

void main(void)
{
    //------------------------------------------------
    // Create a new thread
    thrd_t thread_1;

    int arg = 9990;
    thrd_create(&thread_1, run_in_thread, &arg);

    printf("Doing other things while the thread runs\n");

    printf("Waiting for thread to complete...\n");

    int res;
    thrd_join(thread_1, &res);

    printf("Thread exited with return value %d\n", res);
}