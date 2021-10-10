//heapify a inputted array

#include <iostream>
using namespace std;

 void heapify(int arr[],int n,int i){
     int large =i;
     int leftChild = 2*i+1;
     int rightChild =2*i+2;

     if(leftChild<n && arr[leftChild] > arr[large]){
         large=leftChild;
     }
     if(rightChild<n && arr[rightChild]> arr[large]){
         large=rightChild;
     }
     if(large!=i){
         swap(arr[i],arr[large]);
         heapify(arr,n,large);
     }
 }

 void buildheap(int arr[],int n){
     for(int i=n/2-1;i>=0;i--){
         heapify(arr,n,i);
     }
 }

 void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

 int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    buildheap(arr, n);
 
    cout << "Heapify array  version is \n";
    printArray(arr, n);
}
