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

    // getter : get the value
    string getname(){
        return name;
       // return this->name;    // dono mein se kuch bhi likh skte ho
    }

    //setter : set the value
    void setname(string name){
        this->name=name;
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

    student s("yash",10,100,true);
   
    cout << s.age <<endl;
    //but
    // cout << s.name <<endl; - NOT Accessible

     // get value of name
    cout<<s.getname()<<endl;
    // set the value of name
    s.setname("goyal");
    // get value
    cout<<s.getname()<<endl;
return 0;
}

// note: getter setter se kisi bhi attribute ko kr skte access (public private both)
