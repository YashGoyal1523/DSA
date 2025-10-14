#include<iostream>
using namespace std ;
int main()
{
    int a=1;
    int b=4;

    goto yash;  // yaha se

    cout<<b;              // skipped
                                
    yash:             
    cout<<a;      // yaha pahuchgye

    // goto yash;      // firse uper yash par chale jaayege fir yaha fir uper fir yaha fir uper ...infinite loop bngya

return 0;
}



// note : we can use goto to break multiple loops ek saath
// _ _ _ _
// for(){
//     for(){
//         goto yash;                  it will take us to yash ie out of both loop ie we break out both loops
//     }
// }
// yash:
// _ _ __ 