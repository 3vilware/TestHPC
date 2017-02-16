#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	MPI_Init(&argc,&argv);
	
	int procesadores,len;
	char hostname[MPI_MAX_PROCESSOR_NAME];

	MPI_Comm_size(MPI_COMM_WORLD,&procesadores);
	MPI_Get_processor_name(hostname,&len);
	
	printf("Numero de procesos disponibles: %i \n",procesadores);
	printf("Nombre del host: %s \n", hostname);

	MPI_Finalize();
	return 0;
}
