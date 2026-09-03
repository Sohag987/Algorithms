#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void quicksort(int arr[], int first, int last)
{    
    if (first>=last) return ; 

    int pi = partition(arr, first, last);

    quicksort(arr, first, pi - 1);
    quicksort(arr, pi + 1, last);
}

void printArray(int arr[],int n){
    
    for(int i = 0 ;i<n;i++){
        cout<<arr[i]<<" "; 
    }
}

int main(void)
{
    int arr[] = {2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printArray(arr,n);


    return 0;
}