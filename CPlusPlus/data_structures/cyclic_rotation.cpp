// Time complexity - O(n)
// Space complexity- O(1)

#include<iostream>
using namespace std;

void rotate(int arr[], int n);

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    rotate(arr,n);
    return 0;
}

void rotate(int arr[], int n)
{
    int num=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=num;
    cout<<"The new array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
