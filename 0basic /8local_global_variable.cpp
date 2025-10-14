#include<iostream>    // scope : { }      //global variable-SAME COPY accessible to all scopes 
using namespace std ;                    //local variable- accessible to particular scope
                                            // note: diff scopes m same name ke local variable bana skte...unke name same hoge par memory mein  alag alag hoge...and apne apne scope m accessible hoge




int x=4; // global variable 

void fun1(){
    x=1;   // value of global variable changed to 1 as it is most local .....different functions are independent of each other ie diff scopes 
}
void fun2(){
    cout<<x<<endl; // will print global as most local .......
    x=5; // global varibale will be changed as it is most local
    cout<<x<<endl; // global variable will be print 
    int x=2; // local var of fun()
    cout<<x<<endl; // will print local variable of fun()  as it is most local
    cout<<::x<<endl;

    {
        cout<<x<<endl; // will print local variable of fun() as it is most local
        cout<<::x<<endl;
        int x=10; // local to this scope
        cout<<x<<endl;
    }
}


int main()
{    cout<<::x<<endl; // method to access global variable is by using :: 
    // but note
    cout<<x<<endl; // will also print global variable as currently it is most local here
    x=5; // global varibale will be changed as it is most local
    cout<<x<<endl; // global variable will be print 
    int x=2; // local variable of main()
    cout<<x<<endl; // it will now  print local variable of main()  as now it is most local
     x=6; // local variable to main() will be changed to 6 as it is most local
    //now if we want to access global variable then only option is using ::
    ::x=7; //global variable will be changed to 7
    cout<<x<<endl;
    cout<<::x<<endl;
    // creating another scope 
    {
        cout<<x<<endl; // will print local variable of main() as it is most local
        cout<<::x<<endl;
        int x=10; // local variable of this scope   
        cout<<x<<endl;// local variable of this scope will be print
        x=12; // will change local var of this to 12
        cout<<::x<<endl; // global can be access here like this but now local to main() cant be accessed

    }
     cout<<::x<<endl;
    fun1();
     cout<<::x<<endl;
     fun2();
return 0;
}



// note: modification global variable in one scope will change it in all scopes