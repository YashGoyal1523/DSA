#include<iostream>
using namespace std ;

class student{                                            // private , public, protected are  access modifiers
//private:
    string name;    // name is private (by default is private) (kisi modifier m nhi daala toh private hi h)
 public:
    int age;
    int marks;
    bool hey;

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
    cout<<sizeof(student)<<endl;         
    student s1;                                     // class-student object-s1
    cout<<sizeof(s1)<<endl;
    s1.age=10;
   // s1.name="hello";  //cant be accessed as private
     
return 0;
}