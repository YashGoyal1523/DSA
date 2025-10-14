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
    student(string _name,int _age,int _marks,bool _hey){           
        cout<<"paratemerised ctor called"<<endl;
        name=_name;  
        age=_age;
        marks=_marks;
        hey=_hey;
    }

 // dtor
    ~student(){
        cout<<"student dtor called"<<endl;
       
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
    // dynamic memory allocation
    
   student *s=new student(); // or student *s=new student; // default ctor called
    (*s).age=10;
    cout<<(*s).age<<endl<<s->age<<endl;
    
 student *s1 =new student("yash",10,100,true); // parametrised ctor called

 cout<<(*s1).age<<endl<<s1->age;

     delete s; //( heap memory freed)
     delete s1;
return 0;
}


// understanding k liye...student ko int ki trah datatype se socho