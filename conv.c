/***
// Convolution
// 1d: f[m] = hxg = sum_k(h[m-k]*g[k])
// 2d: f[m,n] = hxg = sum_kl(h[m-k,n-l]*g[k,l])
*/

#include <stdio.h>
#include <stdlib.h>
#include "conv.h"

int main(int argc, char *argv[]) {

    int kernelSize, inputSize;

    // input
    printf("Enter Input Size: ");
    scanf("%d", &inputSize);
    int* input = createArray(inputSize);
    printf("Enter Input: ");
    userInputArray(inputSize, input);

    // kernel
    printf("Enter Kernel Size: ");
    scanf("%d", &kernelSize);
    int* kernel = createArray(kernelSize);
    printf("Enter Kernel: ");
    userInputArray(kernelSize, kernel);

    // 1d convolution
    int* output = createArray(inputSize);
    // conv1D(inputSize, kernelSize, input, kernel);

    free(input);
    free(kernel);
    free(output);

    return 0;
}

int* createArray(int size) {
    int* arr = malloc(size * sizeof(int));
    if (arr==NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }
    return arr;
}

void userInputArray(int size, int* arr) {
    for (int i=0; i<size; i++) {
        scanf("%d", arr+i);
    }
}

// 1d: f[m] = hxg = sum_k(h[m-k]*g[k])
int conv1D(int inputSize, int kernelSize, int* input, int* kernel) {
    for (int i=0; i<inputSize; i++) {
    }
    return 0;
}