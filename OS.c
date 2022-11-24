#include <stdio.h>
#include <sched.h>
#include <pthread.h>
#include <time.h>

void *countfunction1(void *vargp)
{
    
    long long int a;
    long long int count1;
    count1 = 0;
    struct sched_param param0;
    int x;
    param0.sched_priority = 0;
    x = pthread_setschedparam(pthread_self(), SCHED_OTHER, &param0);
    
    if (x == 0)
    {
        for (a = 1; a < 4294967297; ++a)
        {
            count1 = count1 + 1;
        }
    }
    
}

void *countfunction2(void *vargp)
{
    
    long long int b;
    long long int count2;
    count2 = 0;
    struct sched_param param1;
    int y;
    param1.sched_priority = 0;
    y = pthread_setschedparam(pthread_self(), SCHED_RR, &param1);
    if (y == 0)
    {
        for (b = 1; b < 4294967297; ++b)
        {
            count2 = count2 + 1;
        }
    }

}

void *countfunction3(void *vargp)
{
    
    long long int c;
    long long int count3;
    count3 = 0;
    struct sched_param param2;
    int z;
    param2.sched_priority = 30;
    z = pthread_setschedparam(pthread_self(), SCHED_FIFO, &param2);
    if (z == 0)
    {
        for (c = 1; c < 4294967297; ++c)
        {
            count3 = count3 + 1;
        }
    }
}

int main()
{
    pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_t thread_id3;

    clock_t t1;
    t1 = clock();
    pthread_create(&thread_id1, NULL, countfunction1, NULL);
    t1 = clock() -t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("%f\n",time1);
    
    clock_t t2;
    t2 = clock();
    pthread_create(&thread_id2, NULL, countfunction2, NULL);
    t2 = clock() -t2;
    double time2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("%f\n",time2);

    clock_t t3;
    t3 = clock();
    pthread_create(&thread_id3, NULL, countfunction3, NULL);
    t3 = clock() -t3;
    double time3 = ((double)t3)/CLOCKS_PER_SEC;
    printf("%f",time3);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    
}

