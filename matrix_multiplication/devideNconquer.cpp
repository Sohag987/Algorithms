
#include <iostream>
#include <vector>

using namespace std;

using matrix = vector<vector<long long>>;

// Add two matrices
matrix add(const matrix& A, const matrix& B) {
    int n = A.size();

    matrix C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Get a block/sub-matrix
matrix getBlock(const matrix& M, int row, int col, int size) {
    matrix B(size, vector<long long>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            B[i][j] = M[row + i][col + j];
        }
    }

    return B;
}

// Put a block into a matrix
void putBlock(matrix& M, const matrix& B, int row, int col) {
    int size = B.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            M[row + i][col + j] = B[i][j];
        }
    }
}

// Matrix multiplication using divide and conquer
matrix MatrixMultiply(const matrix& A, const matrix& B) {
    int n = A.size();

    // Base case
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int h = n / 2;

    // Divide A into 4 blocks
    matrix A11 = getBlock(A, 0, 0, h);
    matrix A12 = getBlock(A, 0, h, h);
    matrix A21 = getBlock(A, h, 0, h);
    matrix A22 = getBlock(A, h, h, h);

    // Divide B into 4 blocks
    matrix B11 = getBlock(B, 0, 0, h);
    matrix B12 = getBlock(B, 0, h, h);
    matrix B21 = getBlock(B, h, 0, h);
    matrix B22 = getBlock(B, h, h, h);

    // Calculate C blocks
    matrix C11 = add(
        MatrixMultiply(A11, B11),
        MatrixMultiply(A12, B21)
    );

    matrix C12 = add(
        MatrixMultiply(A11, B12),
        MatrixMultiply(A12, B22)
    );

    matrix C21 = add(
        MatrixMultiply(A21, B11),
        MatrixMultiply(A22, B21)
    );

    matrix C22 = add(
        MatrixMultiply(A21, B12),
        MatrixMultiply(A22, B22)
    );

    // Combine the 4 blocks
    matrix C(n, vector<long long>(n, 0));

    putBlock(C, C11, 0, 0);
    putBlock(C, C12, 0, h);
    putBlock(C, C21, h, 0);
    putBlock(C, C22, h, h);

    return C;
}

// Print matrix
void print(const matrix& A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    matrix A = {
        {1, 2},
        {3, 4}
    };

    matrix B = {
        {5, 6},
        {7, 8}
    };

    matrix C = MatrixMultiply(A, B);

    print(C);

    return 0;
}
