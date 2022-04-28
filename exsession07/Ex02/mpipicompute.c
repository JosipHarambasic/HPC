
//
// Created by Josip Harambasic on 27.04.22.
//

#include "mpi.h"
#include <stdio.h>
#define number 1000000000

int main(int argc, char** argv){
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    double sum = 0;
    double pi = 0;
    for (long long n=my_rank; n<number; n+=size) {
        double tmp = 1.0 / ( 2.0 * (double)n + 1);
        if (n % 2 == 0) {
            sum += tmp;
        } else {
            sum -= tmp;
        }
    }
    MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (my_rank == 0){
        printf("approx pi: %.8f", 4*pi);
    }
    MPI_Finalize();
}