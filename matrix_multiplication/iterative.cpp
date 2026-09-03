#include<iostream>
#include<vector>


using namespace std;

using matrix  = vector<vector<long long>>;

matrix iterative_multiplication(const matrix &A , const matrix &B){
    int n = A.size(); 

    matrix C(n,vector<long long>(n,0)); 

    for(int i=0; i<n;i++){
        for(int j = 0 ;j<n;j++){
            for(int k=0;k<n;k++){
                C[i][j] = A[i][k] + B[k][j]; 
            }
        }
    }

    return C ; 
}

void print(const matrix &A){
    int n = A.size(); 
    for(int i = 0 ; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";

        }
        cout<<endl;
    }
}

int main() {
 matrix A = {{1, 2}, {3, 4}};
 matrix B = {{5, 6}, {7, 8}};
 matrix C =iterative_multiplication(A, B);
 print(C);
 return 0;
}