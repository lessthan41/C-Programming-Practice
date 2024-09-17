/***
 * conv2d: f[m,n] = sum_{k,l} h[m-k,n-l] * g[k,l]
 */

#include <iostream>
#include <utility>

using namespace std;

#include "conv2d.h"

int main(int argc, char* argv[]) {

	int inputH, inputW, kernelH, kernelW;

	// create input array
	cout << "Enter Input Size: ";
	cin >> inputH >> inputW;
	pair<int,int> inputShape = make_pair(inputH, inputW);
	int** input = createDynamicArray2D(inputShape);

	// create kernel array
	cout << "Enter Kernel Size: " << endl;
	cin >> kernelH >> kernelW;
	pair<int,int> kernelShape = make_pair(kernelH, kernelW);
	int** kernel = createDynamicArray2D(kernelShape);

	releaseDynamicArray2D(inputShape, input);
	releaseDynamicArray2D(kernelShape, kernel);

	return 0;
}

int** createDynamicArray2D(pair<int,int> shape) {
	int** arr = new int*[shape.first];
	if (arr==nullptr) {
        printf("Memory Allocation Failed");
        exit(1);
    }
	for (int i=0; i<shape.first; i++) {
		arr[i] = new int[shape.second];
		if (arr[i]==nullptr) {
			printf("Memory Allocation Failed");
			exit(1);
		}
	}
	return arr;
}

void releaseDynamicArray2D(pair<int,int> size, int** arr) {
	for (int i=0; i<size.first; i++) {
		delete [] arr[i];
	}
	delete [] arr;
	arr = nullptr;
}