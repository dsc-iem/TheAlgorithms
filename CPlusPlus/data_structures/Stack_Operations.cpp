#include <iostream>
#include <windows.h>
using namespace std;

class stack
{
    private:
        int top;
        int *arr;
        int n;

    public:
        stack(int a)
        {
            n=a;
            arr=new int[n];
            top=-1;
            for (int i=0;i<n;i++)
            {
                arr[i]=0;
            }
        }

        bool isempty()
            {
                if (top==-1)
                return true;
                else
                return false;
            }

        bool isfull()
            {
                if (top==(n-1))
                return true;
                else 
                return false;
            }

        void push(int val)
        {
            if (isfull())
            cout<<"STACK OVERFLOW - THERE'S NO SPACE IN THE STACK"<<endl;
            else
            {
                top++;
                arr[top]=val;
            }
        }

        void pop()
        {
            if (isempty())
            {
                cout<<"STACK UNDERFLOW - THERE'S NO ELEMENT IN THE STACK"<<endl;
            }
            else
            {
                int temp=arr[top];
                arr[top]=0;
                top--;
                cout<<"THE POPPED VALUE IS "<<temp<<endl;
            }
        }

        int count()
        {
            return (top+1);
        }

        void show(int pos)
        {
            if (isempty())
            {
                cout<<"THE STACK IS EMPTY - NO ELEMENT IS PRESENT TO BE SHOWN"<<endl;
            }
            else if (pos>(n-1))
            {
                cout<<"INVALID POSITION INPUT"<<endl;
            }
            else
            {
                cout<<"THE VALUE IS "<<arr[pos]<<endl;;
            }
        }

        void swap(int pos, int val)
        {
            if (pos>top)
            {
                cout<<"INVALID POSITION INPUT"<<endl;
            }
            else
            {
                arr[pos]=val;
                cout<<"VALUE CHANGED AT LOCATION "<<pos<<endl;
            }
        }

        void display()
        {
            cout<<"THE VALUES IN THE STACK ARE AS FOLLOWS-"<<endl;
            for (int i=0;i<n;i++)
            {
                cout<<arr[i]<<endl;
            }
        }
};

int main()
{
    int choice,pos,val;
    int n;
    cout<<endl<<"PLEASE ENTER THE SIZE OF THE STACK"<<endl;
    cin>>n;
    stack s(n);
    
    do
    {
        cout<<endl<<"PLEASE ENTER A CHOICE"<<endl;
        cout<<"1. TO PUSH AN ELEMENT INTO THE STACK"<<endl;
        cout<<"2. TO POP AN ELEMENT FROM THE STACK"<<endl;
        cout<<"3. TO CHECK IF THE STACK IS EMPTY"<<endl;
        cout<<"4. TO CHECK IF THE STACK IS FULL"<<endl;
        cout<<"5. TO SHOW A PARTICULAR ELEMENT"<<endl;
        cout<<"6. TO COUNT THE TOTAL NUMBER OF ELEMENTS IN THE STACK"<<endl;
        cout<<"7. TO CHANGE A PARTICULAR ELEMENT"<<endl;
        cout<<"8. TO DISPLAY ALL THE ELEMENTS"<<endl;
        cout<<"9. TO CLEAR THE SCREEN"<<endl;
        cout<<"10. TO TERMINATE THE PROGRAM"<<endl<<endl;

        cin>>choice;
        switch(choice)
        {
            case (1):
            {
                cout<<"PLEASE ENTER THE ITEM TO BE PUSHED"<<endl;
                cin>>val;
                s.push(val);
                break;
            }

            case (2):
            {
                s.pop();
                break;
            }

            case (3):
            {
                if (s.isempty())
                cout<<"THE STACK IS EMPTY"<<endl;
                else
                cout<<"THE STACK IS NOT EMPTY"<<endl;
                break;
            }

            case (4):
            {
                if (s.isfull())
                cout<<"THE STACK IS FULL"<<endl;
                else
                cout<<"THE STACK IS NOT FULL"<<endl;
                break;
            }

            case (5):
            {
                cout<<"PLEASE ENTER THE POSITION OF THE ELEMENT TO BE DISPLAYED"<<endl;
                cin>>pos;
                s.show(pos);
                break;
            }

            case (6):
            {
                cout<<"THE NUMBER OF ITEMS IN THE STACK ARE "<<s.count()<<endl;
                break;
            }

            case (7):
            {
                cout<<"PLEASE ENTER THE POSITION OF THE ITEM TO BE CHANGED"<<endl;
                cin>>pos;
                cout<<"PLEASE ENTER THE VALUE OF THE ITEM TO BE CHANGED"<<endl;
                cin>>val;
                s.swap(pos,val);
                break;
            }

            case (8):
            {
                s.display();
                break;
            }

            case (9):
            {
                system("cls");
                break;
            }

            default:
            {
                while (choice!=10)
                {
                    cout<<"INVALID INPUT"<<endl;
                }
            }
        }
    }while(choice!=10);
    cout<<"PROGRAM TERMINATED"<<endl;
    return 0;
}
