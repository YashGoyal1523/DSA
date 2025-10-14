#include<iostream>
using namespace std ;

class teacher{
    public:
    void teach(){
        cout<<"teaching";
    }
};

class prof{
    public:
    void read(){
        cout<<"reading";
    }
};

// multiple inheritance

class researcher: public teacher,public prof
{
    void bore(){
        cout<<"boring";
    }
};



int main()
{

    researcher r;
    r.teach();
    r.read();
return 0;
}