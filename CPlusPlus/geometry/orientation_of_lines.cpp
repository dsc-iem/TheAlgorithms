//Used in convex hull problems
#include <iostream>
using namespace std;
struct point
{
    int x,y;
};
int orientation(point p1,point p2,point p3){
    int ans=((p2.y-p1.y)*(p3.x-p2.x))-((p3.y-p2.y)*(p2.x-p1.x));
    return ans;
}
int main(){
    point p1={1,1},p2={2,2},p3={3,2};
    int ans=orientation(p1,p2,p3);
    if(ans==0)
    cout<<"Collinear"<<endl;
    if(ans<0)
    cout<<"Clockwise"<<endl;
    if(ans>0)
    cout<<"Anti -Clockwise"<<endl;
   
    
}

