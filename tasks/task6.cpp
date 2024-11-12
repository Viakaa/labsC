#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10;  

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n, m;

    ifstream inputFile("matrix.txt");
    if (!inputFile) {
        cerr << "Cant open file" << endl;
        return 1;
    }

    inputFile >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();

    ofstream outputFile("matrixOutput.txt");
    ofstream binaryFile("matrixOutput.bin", ios::binary);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
            outputFile << matrix[i][j] << " ";
            binaryFile.write(reinterpret_cast<const char*>(&matrix[i][j]), sizeof(matrix[i][j]));
        }
        cout << endl;
        outputFile << endl;
    }

    outputFile.close();
    binaryFile.close();

    int colsWithZeros = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) {
                colsWithZeros++;
                break;
            }
        }
    }

    int longestRow = -1, maxLength = 0;
    for (int i = 0; i < n; i++) {
        int currentLength = 1;
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == matrix[i][j - 1]) {
                currentLength++;
            }
            else {
                currentLength = 1;
            }
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestRow = i;
            }
        }
    }

    cout << "Number of columns with zero elements:" << colsWithZeros << endl;
    if (longestRow != -1) {
        cout << "Number of row with longest series of same number: " << longestRow + 1 << endl;
    }
    else {
        cout << "There is no row with series of same number" << endl;
    }

    return 0;
}
