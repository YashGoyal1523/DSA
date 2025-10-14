#include<iostream>
using namespace std;
// implement 2 stack using 1 array
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    //ctor
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];

        this->top1 = -1;
        this->top2 = size;  // array mein indexes hote from 0 to size-1
    }
    void push1(int data)
    {
        top1++;
        if (top2 - top1 == 1)               // means dono aage peeche hogye mtlb memory full
        {   // no space available
            cout << "Stack OverFlow!" << endl;    
            return;
        }

        arr[top1] = data;
    }
    void push2(int data)
    {
        top2--;
        if (top2 - top1 == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }

        arr[top2] = data;
    }
    void pop1()
    {
        if (arr[top1] == -1)
        {       // stack 1 is emptyn
            cout << "Stack underFlow!" << endl;
            return;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2()
    {
        if (arr[top2] == size)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }

     int getTop1()
    {   if(top1==-1) {
        cout<<"empty: ";
        return 0;
    }
        else return arr[top1];
    }
    int getTop2()
    { if(top2==size) {
        cout<<"empty";
        return 0;
    }
        else return arr[top2];
    }

    void print(){
        cout<<"top1:"<<top1<<endl;
            cout<<"top2:"<<top2<<endl;
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<endl;
        }
        
    }
};

int main(){
    Stack st(6);
    
    st.print();

    cout<<endl;

    cout<<st.getTop1()<<endl;

    st.push1(1);
    st.push2(1);

cout<<endl;

    st.print();
}