#include<iostream>
using namespace std ;


class person{
    public:
    void breathe(){
        cout<<"breathing"<<endl;
    }
};




class teacher:public person{
    public:
    void teach(){
        cout<<"teaching"<<endl;
    }
};

class prof:public person{
    public:
    void read(){
        cout<<"reading"<<endl;
    }
};

// multiple inheritance

class researcher: public teacher,public prof
{
    void bore(){
        cout<<"boring"<<endl;
    }
};



int main()
{

    researcher r;
  //   r.breathe(); //cant do as confused prof se breathe lena ya teacher se

     //m1 : scope resolution
     r.teacher::breathe();
     r.prof::breathe();

return 0;
}