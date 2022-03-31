#include <cstdlib>
#include <iostream>
#include <stdio.h>


typedef struct complex_vector{
    int img[100];
    int re[100];
} complex_vector;

int linear_combination(complex_vector* x, complex_vector* y, int a, complex_vector* z){
    int array_size = 100;
    for (int i = 0; i < array_size; i++) {
        (*z).re[i] = (*x).re[i] + a * (*y).re[i];
        (*z).img[i] = (*x).img[i] + a * (*y).img[i];
    }
    return 0;
}

int main (int argc, char *argv[])
{
    complex_vector* x = new complex_vector();
    complex_vector* y = new complex_vector();
    complex_vector* z = new complex_vector();

    int a = 1;

    for (int i = 0; i < 100 ; i++) {
        x->img[i] = i;
        y->img[i] = i;
        x->re[i] = i;
        y->re[i] = i;
    }

    linear_combination(x, y, a, z);

    //Just checking if it works
    for (int i = 0; i < 200 ; i++) {
        printf("%d, RE: %d IMG: %d\n", i, z->re[i], z->img[i]);
    }

    return 0;
}
