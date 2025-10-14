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
     

    student s("yash",10,100,true); 

    {
        student s1;
    }
   
    student* s2=new student();
    delete s2;
return 0;
}

// dtor : destroys the object 
// dtor is called when scope of that object(static) gets over ...like here for s its main func ke }  for s1 its uske paas wala } and for dma wala ke liye when we delete object by using delete word
//  dtor added by itself if not written
// why we need to write dtor : hume heap memory delete krni hoti hai..ab agar koi attribute dma se hai toh usko delete krna hoga....ab usko hum dtor ke code mein likh skte....(achi jagah hai as vaha vse bhi sab use khatm hoke end hi hora hai toh vhi delete krdo)(zruri nhi h vhi likho bas aur jagah dhundne ke likhna pdega isse acha yhi likhdo)





// ctor dtor public mein and functions se phle likhte haiii