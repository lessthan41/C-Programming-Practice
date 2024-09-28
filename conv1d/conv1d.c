/**
 * Full padding convolution
 * conv1d: f[m] = hxg = sum_k(h[m-k]*g[k])
 */

#include <stdio.h>
#include <stdlib.h>
#include "conv1d.h"

int main(int argc, char* argv[]) {

    int kernelSize, inputSize;

    // Create input array
    printf("Enter Input Size: ");
    scanf("%d", &inputSize);
    int* input = createArray(inputSize);
    printf("Enter Input: ");
    userInputArray(inputSize, input);

    // Create kernel array
    printf("Enter Kernel Size: ");
    scanf("%d", &kernelSize);
    int* kernel = createArray(kernelSize);
    printf("Enter Kernel: ");
    userInputArray(kernelSize, kernel);

    // Create output array
    int outputSize = inputSize+kernelSize-1;
    int* output = createArray(outputSize);

    // Perform 1D Convolution
    conv1D(inputSize, kernelSize, outputSize, input, kernel, output);

    // Print output
    printOutput(outputSize, output);

    // Release dynamic array
    free(input);
    free(kernel);
    free(output);

    return 0;
}

/**
 * Given size, malloc an 1D array and return
 */
int* createArray(int size) {
    int* arr = malloc(size * sizeof(int));
    if (arr==NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }
    return arr;
}

/**
 * User input 1D array given size and array
 */
void userInputArray(int size, int* arr) {
    for (int i=0; i<size; i++) {
        scanf("%d", arr+i);
    }
}

/**
 * @brief f[m] = hxg = sum_k(h[m-k]*g[k])
 * Perform 1D convolution with full padding
 * @param inputSize size of input 1D array
 * @param kernelSize size of kernel 1D array
 * @param outputSize size of output 1D array
 * @param input input 1D array
 * @param kernel kernel 1D array
 * @param output  convolution output of 1D array
 */
void conv1D(int inputSize, int kernelSize, int outputSize, const int* input, const int* kernel, int* output) {
    for (int m=0; m<outputSize; m++) {
        int sum = 0;
        int lhs = (0 > m-inputSize+1) ? 0 : m-inputSize+1; // m-k<inputSize && k >= 0
        int rhs = (m+1 < kernelSize) ? m+1 : kernelSize; // m-k>=0 && k<kernelSize
        for (int k=lhs; k<rhs; k++) {
            sum += input[m-k] * kernel[k];
        }
        output[m] = sum; // f[m]
    }
}

/**
 * Printing function
 */
void printOutput(int size, const int* output) {
    for (int i=0; i<size; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
}
