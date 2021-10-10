//kadanes algo but after last index you are allowed to go on first index
#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,8,-9,10,1,1,3,5,-15,-19,4};
    int l=sizeof(arr)/sizeof(arr[0]);
    int currentSum=0;
    int maxSum=0;
    int sum=0;
    for(int i=0;i<l;i++)
    {
        sum+=arr[i];
        arr[i]=-arr[i];
    }
    for(int i=0;i<l;i++)
    {   
        currentSum+=arr[i];
        if(arr[i]>currentSum)
            currentSum=arr[i];
        maxSum=max(maxSum,currentSum);
    }
    sum=sum+maxSum;
    cout<<sum;
    return 0;
}
