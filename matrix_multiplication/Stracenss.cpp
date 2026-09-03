
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

// additional Helper function for substraction 

matrix sub(const matrix& A, const matrix& B) {
    int n = A.size();

    matrix C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
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
matrix Stracenss_MatrixMultiply(const matrix& A, const matrix& B) {
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

    matrix M1 = Stracenss_MatrixMultiply(add(A11,A22),add(B11,B22));
    matrix M2 = Stracenss_MatrixMultiply(add(A21,A22),B11); 
    matrix M3 = Stracenss_MatrixMultiply(A11,sub(B12,B22)); 
    matrix M4 = Stracenss_MatrixMultiply(A22,sub(B21,B11)); 
    matrix M5 = Stracenss_MatrixMultiply(add(A11,A12),B22); 
    matrix M6 = Stracenss_MatrixMultiply(sub(A21,A11),add(B11,B12)); 
    matrix M7 = Stracenss_MatrixMultiply(sub(A12,A22),add(B21,B22)); 

    matrix C11 = add(sub(add(M1,M4),M5),M7); 
    matrix C12 = add(M3,M5); 
    matrix C21 = add(M2,M4); 
    matrix C22 = add(add(sub(M1,M2),M3),M6); 


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

    matrix C = Stracenss_MatrixMultiply(A, B);

    print(C);

    return 0;
}
