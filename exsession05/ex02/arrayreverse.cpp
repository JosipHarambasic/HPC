#include <cstdlib>
#include <iostream>
#include <stdio.h>


int main (int argc, char *argv[])
{
    int** M = new int *[2];
    M[0] = new int[5]{0,1,2,3,4};
    M[1] = new int[5]{5,6,7,8,9};

    int** M2 = new int *[2];
    M2[0] = new int[5];
    M2[1] = new int[5];

    int *p = *M + 4; // = 4
    int *q = *(M+1) + 4; // = 9
    int *o = *M2;
    int *i = *(M2+1);

    int counter = 0;

    for (int z = 0; z < 5; z++){
        *(o+z) = *(q-counter);
        *(i+z) = *(p-counter);
        counter++;

        printf("%d\n",M2[0][z]);
        printf("%d\n",M2[1][z]);

    }
}