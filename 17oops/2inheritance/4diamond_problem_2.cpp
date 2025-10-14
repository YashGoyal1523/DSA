#include<iostream>
using namespace std ;       // m2 : virtual inherit kro person ko prof ,teacher mein


class person{
    public:
    void breathe(){
        cout<<"breathing"<<endl;
    }
};




class teacher: virtual public person{   //virtual
    public:
    void teach(){
        cout<<"teaching"<<endl;
    }
};

class prof:virtual public person{     // virtual
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

    r.breathe(); // hojayga
  
return 0;
}