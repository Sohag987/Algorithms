#include<iostream>

using namespace std; 

void merge(int arr[],int l, int mid , int r){
    int i = 0 , j = 0 , k = l ; 
      int size_of_a = mid -l +1; 
      int size_of_b = r - mid ; 
      int left_sub_array[size_of_a] , right_sub_array[size_of_b]; 

    for(int i = 0 ;i<size_of_a;i++){
        left_sub_array[i] = arr[l+i]; 

      }

    for (int j = 0 ;j<size_of_b;j++){
        right_sub_array[j] =  arr[mid+1+j];
      }

    while(i<size_of_a && j < size_of_b){
        if(left_sub_array[i]<right_sub_array[j]) arr[k++] = left_sub_array[i++]; 
        else if (left_sub_array[i]>right_sub_array[j]) arr[k++] = right_sub_array[j++] ; 
        else arr[k++] = left_sub_array[i++];
      }

    while(i<size_of_a) {
        arr[k++] = left_sub_array[i++];
    }

    while(j<size_of_b){
        arr[k++] = right_sub_array[j++]; 
    }
}

void mergeSort(int arr[], int l , int r){
    if (l>=r){
        return ; 
    }

    int mid = (l+r)/2; 

    mergeSort(arr ,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);


}

void printArray(int arr[], int size){
    for(int i = 0 ;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {10,28,24,6,34,18,38,44};
    int n = sizeof(arr)/sizeof(arr[0]);
    int r = n-1 ;
    mergeSort(arr,0,r);
    printArray(arr,n);


    

}