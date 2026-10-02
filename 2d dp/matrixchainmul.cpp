#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;  // Number of matrices

    cout << "Enter the number of matrices: ";
    cin >> n;

    // Vector for storing dimensions of each matrix
    vector<pair<int, int>> dimensions(n);

    cout << "Enter dimension of each matrix:\n";

    for (int i = 0; i < n; i++) {

        cout << "A" << i + 1 << " rows columns: ";

        cin >> dimensions[i].first;
        cin >> dimensions[i].second;
    }

    // Dimension array
    // If there are n matrices, there are n+1 dimensions
    vector<int> dimarray(n + 1, 0);

    dimarray[0] = dimensions[0].first;

    for (int i = 1; i <= n; i++) {
        dimarray[i] = dimensions[i - 1].second;
    }

    // Print dimension array
    cout << "\nDimension array:\n";

    for (int i = 0; i <= n; i++) {
        cout << dimarray[i] << " ";
    }

    cout << "\n";


    // Cost table and K table
    // We use 1-based indexing, so size must be n+1
    vector<vector<int>> costTable(
        n + 1,
        vector<int>(n + 1, 0)
    );

    vector<vector<int>> kTable(
        n + 1,
        vector<int>(n + 1, 0)
    );


    // Matrix Chain Multiplication DP
    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            costTable[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int current_cost =
                    costTable[i][k]
                    + costTable[k + 1][j]
                    + dimarray[i - 1]
                    * dimarray[k]
                    * dimarray[j];

                if (current_cost < costTable[i][j]) {

                    costTable[i][j] = current_cost;

                    kTable[i][j] = k;
                }
            }
        }
    }


    // Print Cost Table
    cout << "\nCost Table:\n";

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            cout << costTable[i][j] << "\t";
        }

        cout << endl;
    }


    // Print K Table
    cout << "\nK Table:\n";

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            cout << kTable[i][j] << "\t";
        }

        cout << endl;
    }


    return 0;
}