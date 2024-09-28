/**
 * Full padding convolution
 * conv2d: f[m,n] = sum_{k,l} h[m-k,n-l] * g[k,l]
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#include "conv2d.h"

int main(int argc, char* argv[]) {

    int inputH, inputW, kernelH, kernelW;

    // Create input vector
    cout << "Enter Input Size: ";
    cin >> inputH >> inputW;
    pair<int,int> iShape = make_pair(inputH, inputW);
    vector<vector<int>> input(iShape.first, vector<int>(iShape.second));
    cout <<"Enter Input: ";
    userInputVector(iShape, input);

    // Create kernel vector
    cout << "Enter Kernel Size: ";
    cin >> kernelH >> kernelW;
    pair<int,int> kShape = make_pair(kernelH, kernelW);
    vector<vector<int>> kernel(kShape.first, vector<int>(kShape.second));
    cout <<"Enter Kernel: ";
    userInputVector(kShape, kernel);

    // Create output vector
    pair<int,int> oShape = make_pair<int,int>(
        iShape.first+kShape.first-1,iShape.second+kShape.second-1
    );
    vector<vector<int>> output(oShape.first, vector<int>(oShape.second));

    // Perform convolution 2D
    conv2D(iShape, kShape, oShape, input, kernel, output);

    // Print output
    printOutput(oShape, output);

    return 0;
}

/**
 * User input 2D vector by cin
 * @param shape is the shape of vector to be input
 * @param arr is the vector to be input
 */
void userInputVector(pair<int,int> shape, vector<vector<int>> &vec) {
    int value;
    for (int i=0; i<shape.first; i++) {
        for (int j=0; j<shape.second; j++) {
            cin >> vec[i][j];
        }
    }
}

/**
 * @brief conv2D: f[m,n] = sum_{k,l} h[m-k,n-l] * g[k,l]
 * @param iShape is the input 2D vector shape
 * @param kShape is the kernel 2D vector shape
 * @param oShape is the output 2D vector shape
 * @param input is the input 2D vector
 * @param kernel is the kernel 2D vector
 * @param output is the output 2D vector to save result to
 */
void conv2D(pair<int,int> iShape, pair<int,int> kShape, pair<int,int> oShape, const vector<vector<int>> &input, const vector<vector<int>> &kernel, vector<vector<int>> &output) {
    for (int m=0; m<oShape.first; m++) {
        for (int n=0; n<oShape.second; n++) {
            int sum = 0;
            int klhs = max(0, m-iShape.first+1); // k>=0 && m-k<iShape.first
            int krhs = min(kShape.first, m+1); // k<kShape.first && m-k>=0
            int llhs = max(0, n-iShape.second+1); // l>=0 && n-l<iShape.second
            int lrhs = min(iShape.first, n+1); // l<kShape.second && n-l>=0
            for (int k=klhs; k<krhs; k++) {
                for (int l=llhs; l<lrhs; l++) {
                    sum += input[m-k][n-l] * kernel[k][l];
                }
            }
            output[m][n] = sum;
        }
    }
}

/**
 * Printing function
 */
void printOutput(pair<int,int> oShape, const vector<vector<int>> &output) {
    for (int i=0; i<oShape.first; i++) {
        for (int j=0; j<oShape.second; j++) {
            cout << output[i][j] << " ";
        }
        cout << "\n";
    }
}
