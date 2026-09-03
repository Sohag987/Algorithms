#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<float> bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);
    
    for(float num : arr) {
        int index = n * num;
        buckets[index].push_back(num);
    }
    
    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    vector<float> results;
    for(int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            results.push_back(num);
        }
    }
    return results;
}

int main() {
    cout << "Input size of your array: ";
    int n;
    cin >> n;
    
    if (n <= 0) {
        cout << "Enter a valid number." << endl;
        return 0;
    }
    
    vector<float> arr(n);
    cout << "Enter your decimal numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0.0f || arr[i] > 1.0f) {
            cout << "Not a valid input...";
            return 0;
        }
    }
    
    cout << "Original array: ";
    for(float num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<float> sortedArr = bucketSort(arr);
    
    cout << "Sorted Array: ";
    for(float num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}