#include <iostream>
using namespace std;

void mergeArr(int arr1[],int size1,int arr2[],int size2,int arr3[]);

int main()
{
    int size1,size2;
    cout<<"Enter the no of elements in the first array: ";
    cin>>size1;
    cout<<"Enter the no of elements in the second array: ";
    cin>>size2;
    int arr1[size1],arr2[size2];
    cout<<"Enter the first array: "<<endl;
    for(int i=0;i<size1;i++)
        cin>>arr1[i];
    cout<<"Enter the second array: "<<endl;
    for(int i=0;i<size2;i++)
        cin>>arr2[i];
    int arr3[size1+size2]; //merged array

    mergeArr(arr1,size1,arr2,size2,arr3);
    cout<<"The merged array is: ";
    for(int i=0;i<size1+size2;i++)
        cout<<arr3[i]<<" ";
    return 0;
}

void mergeArr(int arr1[],int size1,int arr2[],int size2,int arr3[])
{
    int i,j,k;
    i=j=k=0;

    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];

        else
            arr3[k++]=arr2[j++];
    }

    //For remaining elements
    while(i<size1)
        arr3[k++]=arr1[i++];

    while(j<size2)
        arr3[k++]=arr2[j++];
}
