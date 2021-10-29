#include <iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int main(){
    int arr[] ={1,2,4,5,6,7,8,32,4,5,7,4,3,21,1,3,5,6,7,5,3,3,2,2,2,3,4,4,4,4,3,3,3,3,4,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    unordered_map<int ,int > map;
    for (int i=0;i<len;i++)
        map[arr[i]]++;
    priority_queue<pair<int,int>> maxHeap;
    for (auto i: map){
        maxHeap.push(make_pair(i.second,i.first));
    }
    while(maxHeap.empty()==false){
        int value=maxHeap.top().second;
        int freq =maxHeap.top().first;
        for(int i=0;i<freq;i++)
            cout<<value<<" ";
        maxHeap.pop();
    }
    return 0;
}
