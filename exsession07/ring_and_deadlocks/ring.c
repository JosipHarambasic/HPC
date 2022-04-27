#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Status status;
    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = 0;        // Receive buffer

    // Compute the ranks of left/right neighbours
    int left_rank, right_rank;
    right_rank = (my_rank+1)%size;
    left_rank = my_rank == 0 ? size - 1 : my_rank - 1;

    for (int i = 0; i < size*2; i++){
        if (i%2 == 0){
            if (my_rank%2==0){
                MPI_Ssend(&send_rank,1, MPI_INT,right_rank,0, MPI_COMM_WORLD);
            } else{
                MPI_Recv(&recv_rank, 1, MPI_INT, left_rank, 0, MPI_COMM_WORLD, &status);
                my_sum += recv_rank;
            }
        }
        else{
            if (my_rank%2 == 1){
                MPI_Ssend(&send_rank, 1, MPI_INT, right_rank, 0, MPI_COMM_WORLD);
                send_rank = recv_rank;
            }
            else
            {
                MPI_Recv(&recv_rank, 1, MPI_INT, left_rank, 0, MPI_COMM_WORLD, &status);
                my_sum += recv_rank;
                send_rank = recv_rank;
            }
        }
    }

    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);
    // Finalize the MPI environment.
    MPI_Finalize();
}


