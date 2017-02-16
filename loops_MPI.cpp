
///MPI LOOPS 
#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
    MPI::Init(argc, argv);

    // get the number of processes, and the id of this process
    int rank = MPI::COMM_WORLD.Get_rank();
    int nprocs = MPI::COMM_WORLD.Get_size();

    // we want to perform 1000 iterations in total. Work out the 
    // number of iterations to perform per process...
    int count = 1000 / nprocs;

    // we use the rank of this process to work out which
    // iterations to perform.
    int start = rank * count;
    int stop = start + count;

    // now perform the loop
    int nloops = 0;

    for (int i=start; i<stop; ++i)
    {
        ++nloops;
    }

    std::cout << "Process " << rank << " performed " << nloops 
              << " iterations of the loop.\n";

    MPI::Finalize();

    return 0;
}
