#include<iostream>
using namespace std ;

class student{
private:
    string name;
 public:
    int age;
    int marks;
    bool hey;

// default ctor
    student(){
        cout<<"ctor called"<<endl;
    }

    void sit(){
        cout<<"sitting";
    }
 private:
    void study(){
        cout<<"studying";
    }
}; 

int main()
{
    student s1;    // default ctor called 
   cout<<s1.marks<<endl; // garbage value assigned will be print
   s1.marks=10;
   cout<<s1.marks;  // user assigned value will print
return 0;
}

// ctor: creates object
// default ctor gets itself added if we dont write it