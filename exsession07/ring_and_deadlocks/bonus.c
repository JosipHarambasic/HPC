//
// Created by Josip Harambasic on 27.04.22.
//

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

    int dim[] = {size};
    int per[] = {1};
    MPI_Request reqs[2*size];

    MPI_Comm COMM_CART;

    MPI_Cart_create(MPI_COMM_WORLD,1,dim,per,1,&COMM_CART);

    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = 0;        // Receive buffer

    // Compute the ranks of left/right neighbours
    int left_rank, right_rank;
    MPI_Cart_shift(COMM_CART, 0, 1, &my_rank, &right_rank);
    MPI_Cart_shift(COMM_CART,0, -1,&my_rank,&left_rank);

    for (int i = 0; i < size; i++) {
        MPI_Irecv(&recv_rank,1, MPI_INT,left_rank,0, MPI_COMM_WORLD, &reqs[i]);
        MPI_Isend(&send_rank,1, MPI_INT,right_rank,0, MPI_COMM_WORLD, &reqs[i+size]);
        MPI_Wait(&reqs[i], &status);
        MPI_Wait(&reqs[i+size], &status);

        my_sum += recv_rank;
        send_rank = recv_rank;
    }

    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);
    // Finalize the MPI environment.
    MPI_Finalize();
}


