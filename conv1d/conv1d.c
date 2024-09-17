/***
 * conv1d: f[m] = hxg = sum_k(h[m-k]*g[k])
 */

#include <stdio.h>
#include <stdlib.h>
#include "conv1d.h"

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
    int outputSize = inputSize+kernelSize-1;
    int* output = createArray(outputSize);
    conv1D(inputSize, kernelSize, outputSize, input, kernel, output);

    // print output
    printOutput(outputSize, output);

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
void conv1D(int inputSize, int kernelSize, int outputSize, int* input, int* kernel, int* output) {
    for (int m=0; m<outputSize; m++) {
        int sum = 0;
        for (int k=0; k<kernelSize; k++) {
            if (m-k<0 || m-k>=inputSize) continue;
            sum += input[m-k] * kernel[k];
        }
        output[m] = sum; // f[m]
    }
}

void printOutput(int size, int* output) {
    for (int i=0; i<size; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
}
