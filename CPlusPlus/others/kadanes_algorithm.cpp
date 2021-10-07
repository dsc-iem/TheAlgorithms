/*In this problem, we have to find the maximum subset of array for which the value of that subset array the sum if its element is greatest , so what we are doing is iterating through all the elements of the array and storing the max value such that the value candidates are current element value and the sum of elements of current element and previous element. Though such way we can can store the max value and print.
T.C. O(N)
S.C. O(1)

We can also use this algorithm to print the array whare we have to print the elements from the max position and position lesser than max value and first smallest negative value.
*/

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int arr[]={3,5,-9,1,3,-2,3,4,7,2,-9,6,3,1,-5,4},k=0,n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        arr[i]=max(arr[i],arr[i]+arr[i-1]);
        k=max(arr[i],k);
    }
    printf("Maximum value for current array is:: %d\n",k);
}
