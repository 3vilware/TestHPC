
#include "mpi.h"
#include <stdio.h>
 
int main( int argc, char *argv[] )
{
    int provided, claimed;
 
/*** Select one of the following
    MPI_Init_thread( 0, 0, MPI_THREAD_SINGLE, &provided ); //level 0 only one thread will execute
    MPI_Init_thread( 0, 0, MPI_THREAD_FUNNELED, &provided ); //Level 1: The process may be multi-threaded, but only the main thread will make MPI calls - all MPI calls are funneled to the main thread.
    MPI_Init_thread( 0, 0, MPI_THREAD_SERIALIZED, &provided ); //  Level 2: The process may be multi-threaded, and multiple threads may make MPI calls, but only one at a time. That is, calls are not made concurrently from two distinct threads as all MPI calls are serialized.
    MPI_Init_thread( 0, 0, MPI_THREAD_MULTIPLE, &provided ); Level 3: Multiple threads may call MPI with no restrictions.
***/ 

    MPI_Init_thread(0, 0, MPI_THREAD_SINGLE, &provided );
    MPI_Query_thread( &claimed );
        printf( "Query thread level= %d  Init_thread level= %d\n", claimed, provided );
 
    MPI_Finalize();
}
