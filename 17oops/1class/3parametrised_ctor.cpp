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

// parameterised ctor
    student(string _name,int _age,int _marks,bool _hey){            // idhar names thode change krlena vrna same rkhoge toh next step mein age=age ese aayega and compiler confuse yeh function parameter wala age hai ya uper class wala..and garbage value aajayegi....par agar same kroge toh ek soln hai ...this pointer 
        cout<<"paratemerised ctor called"<<endl;
        name=_name;  
        age=_age;
        marks=_marks;
        hey=_hey;
    }

// // uper wala is old style for ctor
// //new style is using initialisation list
//    student(string _name,int _age,int _marks,bool _hey) : name(_name) , age(_age) , marks(_marks) , hey(_hey) {}
// // note
//    student(string _name,int _age,int _marks,bool _hey) : name(_name) , age(_age) , marks(_marks) , hey(_hey) {
//     cout<<"in init list"<<endl;
//  }
//  // note
//    student(string _name,int _age,int _marks,bool _hey) : name(_name) , age(_age) , marks(_marks) , hey(_hey) {
//    cout<<"in init list"<<endl;
//    age=10;   // pgle age mein _age dalega fir 10 dalega
//  }


    // parameterised ctor without marks
    student(string _name,int _age,bool _hey){
        cout<<"paratemerised ctor called without marks"<<endl;
        name=_name;
        age=_age;
        hey=_hey;
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

    student s2("yash",10,100,true);  //parametrised called

    cout<<s2.age<<endl;
   // cout<<s2.name; // cant be accessed as private

   s2.age=12; // value changed
   cout<<s2.age<<endl;

   student s3("yash",10,true);//parametrised called without marks

  
return 0;
}


// paramaterised add krne ke baad default apne aap add nhi hoga