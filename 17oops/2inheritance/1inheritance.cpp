#include<iostream>
using namespace std ;

class bird{
    public:
    int age,weight,legs;
    string color;

    void eat(){
        cout<<"eating"<<endl;
    }
     void fly(){
        cout<<"flying"<<endl;
    }
};

 class sparrow: public bird {                  // class  child_class_name :  mode_of_inheritance   parent_class_name 
        public:

        //ctor
        sparrow(int age,int weight,string color,int legs){
            this->age=age;
            this->weight=weight;
            this->color=color;
            this->legs=legs;
        }

         
        void grass(){
            cout<<"grassing"<<endl; 

        }
    };

    class pigeon: public bird {
        public:
        void gutter(){
            cout<<"guttering"<<endl;
        }
    };




int main()
{
   sparrow s(10,10,"black",10); 
    cout<<s.color<<endl;
    s.eat();
    s.fly();

     pigeon p;  
     p.gutter();
return 0;
} 