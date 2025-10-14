//static data member

#include <iostream>
using namespace std;

class abc
{
public:
    static int x, y;
    void print() const
    {
        cout << x << " " << y << endl;
    }
};
int abc::x;
int abc::y; // these variables will be shared among all instances

int main()
{
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();

    abc obj2;
    obj2.y = 20;
    obj2.x = 10;
    obj1.print();
    obj2.print();

    abc::x=5;
    abc::y=5;
    obj1.print();
    obj2.print();
    return 0;
}


// static member function

// #include <iostream>
// using namespace std;

// class abc
// {
// public:
//     static int x, y;
//     static void print()    // function is shared among all instances
//     {
//         cout << x << " " << y << endl;
//     }
// };
// int abc::x;
// int abc::y;


// int main()
// {
//     abc obj1;
//     abc::x = 1;
//     abc::y = 2;
//     abc::print();

//     abc obj2;
//     abc::x = 10;
//     abc::y = 20;
//     abc::print();
//     abc::print();

//     return 0;
// }