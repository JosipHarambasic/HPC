#include "mpi.h"
#include <stdio.h>
#include "init.h"

int start_MPI(int* my_rank, int* size){
	printf("Setting MPI environment\n");
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,size);
	MPI_Comm_rank(MPI_COMM_WORLD,my_rank);

	return 0;
}

int close_MPI(){
	MPI_Finalize();
	return 0;
}

int mpi_get_domain(int nx, int ny, int my_rank, int size, int* min_x, int* max_x, int* min_y, int* max_y){
	/*
	define corners or local domains
	*/

    min_y = 0;
    max_y = &ny;

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Ask MPI to decompose our processes in a 2D cartesian grid for us
    int dims[2] = {0, 0};
    MPI_Dims_create(size, 2, dims);

    // Make both dimensions periodic
    int periods[2] = {true, true};

    // Let MPI assign arbitrary ranks if it deems it necessary
    int reorder = true;

    // Create a communicator given the 2D torus topology.
    MPI_Comm new_communicator;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, reorder, &new_communicator);

    printf("in mpi_get_domain() in mpi_module.cpp,  define corners of the local domains\n");

	printf("I am rank %d and my domain is: xmin, xmax, ymin, ymax: %d %d %d %d\n",my_rank,*min_x,*max_x,*min_y,*max_y);
	return 0;
}

int halo_comm(params p, int my_rank, int size, double** u, double* fromLeft, double* fromRight){
	
	/*this function, vectors fromLeft and fromRight should be received from the neighbours of my_rank process*/
	/*if you want to implement also cartesian topology, you need fromTop and fromBottom in addition to fromLeft a
	nd fromRight*/

	for (int j=0;j<(p.ymax - p.ymin);j++) {
        fromLeft[j] = 0;
        fromRight[j] = 0;
    } //initialize fromLeft and fromRight

    /* define columns to be sent to right neighbour and to the left neighbour, 
    also receive one both form left and right neighbour*/

    //Vectors to send to left and right
    double* sendRight = new double [p.ymax - p.ymin];
    for (int j=0;j<(p.ymax - p.ymin);j++) sendRight[j] = u[p.xmax - p.xmin - 1][j];
    double* sendLeft = new double [p.ymax - p.ymin];
    for (int j=0;j<(p.ymax - p.ymin);j++) sendLeft[j] = u[0][j];

    for (int i = 0; i < size*2; i++) {
        if (my_rank % 2 == 0){
            if (i % 2 == 0){
                if (my_rank != size-1) {
                    MPI_Ssend(&sendRight, 1, MPI_DOUBLE, my_rank + 1, 1, MPI_COMM_WORLD);
                }
                MPI_Ssend(&sendLeft, 1, MPI_DOUBLE, my_rank-1, 1, MPI_COMM_WORLD);
            } else{
                if (my_rank != 0){
                    MPI_Recv(&fromLeft, 1, MPI_DOUBLE, my_rank-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                MPI_Recv(&fromRight, 1, MPI_DOUBLE, my_rank+1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
        } else{
            if (i % 2 == 0){
                if (my_rank != size-1) {
                    MPI_Ssend(&sendRight, 1, MPI_DOUBLE, my_rank + 1, 1, MPI_COMM_WORLD);
                }
                MPI_Ssend(&sendLeft, 1, MPI_DOUBLE, my_rank-1, 1, MPI_COMM_WORLD);
            } else{
                if (my_rank != 0){
                    MPI_Recv(&fromLeft, 1, MPI_DOUBLE, my_rank-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                MPI_Recv(&fromRight, 1, MPI_DOUBLE, my_rank+1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
        }
    }


    /* choose either to define MPIcolumn_type (lines 43-45) or define 
    the columns to be sent manually (lines 53-56)*/

    // MPI_Datatype column_type;
    // MPI_Type_vector(p.ymax - p.ymin, 1, p.xmax - p.xmin, MPI_DOUBLE, &column_type);
    // MPI_Type_commit(&column_type);

    // ...some code goes here and then do not forget to free the column_type

    // MPI_Type_free(&column_type);

	//or alternative approach below

	// double* column_to_right = new double [p.ymax - p.ymin];
	// for (int j=0;j<(p.ymax - p.ymin);j++) column_to_right[j] = u[p.xmax - p.xmin - 1][j]; 
	// double* column_to_left = new double [p.ymax - p.ymin];
	// for (int j=0;j<(p.ymax - p.ymin);j++) column_to_left[j] = u[0][j]; 


	printf("mpi_module.cpp, define halo comm:  \n");
	return 0;
}


int ALLREDUCE(double* loc_diff, double* loc_sumdiff){

	MPI_Allreduce(loc_diff, loc_sumdiff, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return 0;

	}

