/*
 * C program to compute the value of pi using Monte Carlo
 *
 * Command-line arguments:  number_of_samples, seed
 *
 * Preliminary MPI parallel version.  Does not work well -- results
 * vary depending on the number of processes, and are worse for more
 * processes (for reasons as discussed in class).
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   /* has fabs() */
#include <sys/time.h>

/* main program */

unsigned int mysecond()
{
        struct timeval tp;
        struct timezone tzp;
        int i;

        i = gettimeofday(&tp,&tzp);
        return ( (unsigned int) tp.tv_sec + (unsigned int) tp.tv_usec * 1.e-6);
}


int main(int argc, char* argv[]) {

    int num_samples,i;
    int seed;
    double start_time, end_time;
    int count, local_count = 0;
    double x, y;
    double pi = 0.0;
    int nprocs=1;

    /* process command-line arguments */
    if (argc != 2)  { 
        fprintf(stderr, "usage:  %s number_of_samples\n", argv[0]);
   	exit(1); 
	}
    num_samples = atoi(argv[1]);
    seed = mysecond();
    if ((num_samples <= 0) || (seed <= 0)) {
        fprintf(stderr, "usage:  %s number_of_samples\n", argv[0]);
	exit(1);
    }

    /* do calculation */ 
    srand((unsigned int) seed);
    for (i = 0; i < num_samples; i += nprocs) {
        x = (double) rand() / (double) (RAND_MAX);
        y = (double) rand() / (double) (RAND_MAX);
        if ((x*x + y*y) <= 1.0)
            ++local_count;
    }
	count=local_count;
        pi = 4.0 * (double) count / (double) num_samples;

        printf("Program results with %d processes:\n", nprocs);
        printf("number of samples = %d, seed = %d\n", num_samples, seed);
        printf("estimated pi = %12.10f\n", pi);
        printf("difference between estimated pi and math.h M_PI = %12.10f\n",fabs(pi - M_PI));
    return EXIT_SUCCESS;
}

