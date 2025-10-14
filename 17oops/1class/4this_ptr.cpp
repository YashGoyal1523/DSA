#include<iostream>
using namespace std ;                       // in class there is a hidden attribute (added by compiler in private) which is of pointer type and named this which points to current object........( class_name *this;  )

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

// parameterised ctor
    student(string name,int age,int marks,bool hey){            
        cout<<"paratemerised ctor called"<<endl;
        this->name=name;  //or (*this).name
        this->age=age;
        this->marks=marks;
        this->hey=hey;
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
    student s2("yash",10,100,true);
    cout<<s2.age;   // bina this ke kroge toh garbage value aayegi as same name hai func parameter and uper class m

  
return 0;
}


// this pointer points to current object

