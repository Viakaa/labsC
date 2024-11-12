#include <iostream>
#include "header.h"
using namespace std;

int main() {
    const int N = 20;
    int arr[N];
    int n;

    cout << "Enter the number of elements (max " << N << "): ";
    cin >> n;

    INPUT_ARRAY(arr, n);
    OUTPUT_ARRAY(arr, n);

    int product;
    PRODUCT_OF_EVEN_INDEX(arr, n, product);
    cout << "Product of elements at even indices: " << product << endl;

    int sum;
    SUM_BETWEEN_ZEROES(arr, n, sum);
    cout << "Sum between first and last zeros: " << sum << endl;

    REARRANGE_ARRAY(arr, n);
    OUTPUT_ARRAY(arr, n);

    return 0;
}
