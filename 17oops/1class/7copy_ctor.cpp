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
    student(string _name,int _age,int _marks,bool _hey){            // idhar names thode change krlena vrna same rkhoge toh next step mein age=age ese aayega and compiler confuse yeh function wala age hai ya uper class wala....par agar same kroge toh ek soln hai ...this pointer
        cout<<"paratemerised ctor called"<<endl;
        name=_name;  
        age=_age;
        marks=_marks;
        hey=_hey;
    }
   
   // copy ctor
   student(const student &srcobj){                      // & use kiya for by reference // const likhna zruri nhi h bas achi practice hai taaki srcobj read only rhe and uske data m chedh chaad na hoske
        cout<<"student copy ctor gets called"<<endl;
        this->name=srcobj.name;
        this->marks=srcobj.marks;
        this->age=srcobj.age;
        this->hey=srcobj.hey;

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
    

    student s1("yash",10,100,true);  
    

    //m1
    student s2=s1; // ese krege toh s1 copy hogya s2 mein par default call nhi hoga for s2 but note: copy ctor will be called
    //or
    student s3(s1); 

    // m1 se krege toh copy hogya par default ctor call nhi hoga ....instead copy ctor gets  called


    //m2
    student s4; 
    s4=s1; // s1 copied to s4
    cout<<s1.age<<endl<<s4.age<<endl;

    // note m2 mein default ctor toh call hojayega (line 62 mein) par copy ctor nhi hoga as  copy ctor is called during construction par construction(line 62) ke time copy nhi kiya toh no call
return 0;
}

// copy ctor gets itself added if we dont write it (written in public)
// why we need to write copy ctor : copy ctor when written does deep copy.....m1 mein deep copy hori and m2 mein shallow..... note: agar compiler add krra copy ctor toh shallow copy hi hoga  m1 m2 sabme 