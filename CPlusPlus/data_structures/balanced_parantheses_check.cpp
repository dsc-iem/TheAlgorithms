// Check for balanced parentheses using stack
// Time complexity - O(n)
// Space complexity - O(n)

#include<iostream>
#include<string>
using namespace std;
int top{-1};

void push(char ch,char myStack[]);
void pop();
int findTop(char myStack[]);
bool isEmpty();
bool isPair(char ch,char myStack[]);
bool checkParantheses(string A);

int main()
{
    string A;
    cout<<"\nEnter the string to check for balanced parantheses: ";
    getline(cin,A);
    if(checkParantheses(A)==true)
        cout<<"Balanced";
    else
        cout<<"Not balanced";
    return 0;
}

bool checkParantheses(string A)
{
    char myStack[A.length()];
    
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='(' || A[i]=='{' || A[i]=='[')
            push(A[i],myStack);
        else if(A[i]==')' || A[i]=='}' || A[i]==']')
        {
            if((isEmpty()==true) || (isPair(A[i],myStack)==false))
                return false;
            else
                pop();
        }
    }

    if(isEmpty()==true)
        return true;
    else
        return false;
}

void push(char ch,char myStack[])
{
    myStack[++top]=ch;
}

void pop()
{
    if(isEmpty()==true)
        return;
    top--;
}

int findTop(char myStack[])
{
    return myStack[top];
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

bool isPair(char ch,char myStack[])
{
    char topChar=findTop(myStack);
    if(ch==')' && topChar=='(' || ch=='}' && topChar=='{' || ch==']' && topChar=='[')
        return true;
    else
        return false;
}
