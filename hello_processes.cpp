#include <mpi.h>
#include <iostream>

int main(int argc, char **argv)
{
    // Initialise MPI
    MPI_Init(&argc, &argv);

    // Get the number of cores in the MPI cluster
    int nprocs = MPI::COMM_WORLD.Get_size();

    // Get the ID number of this core in the MPI cluster
    int rank = MPI::COMM_WORLD.Get_rank();

    std::cout << "I am process " << rank
              << ". The number of processes is " << nprocs << ".\n";

    // Shut down MPI
    MPI::Finalize();

    return 0;
} 
