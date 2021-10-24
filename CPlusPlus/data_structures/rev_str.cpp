#include<iostream>
using namespace std;
#include<string>
#include<stack>

string strRev(string A);

int main()
{
    string A;
    cout<<"Enter a string: ";
    getline(cin,A);
    cout<<"The reverse is: "<<strRev(A);
    return 0;
}

string strRev(string A)
{
    stack<char> myStack;
    for(int i=0;i<A.length();i++)
        myStack.push(A[i]);
    for(int i=0;i<A.length();i++)
    {
        A[i]=myStack.top();
        myStack.pop();
    }
    return A;
}

