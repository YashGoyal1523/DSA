// the ternary or conditional operator ( ? : ) is the shortest form of writing conditional statements. It can be used as an inline conditional statement in place of if-else to execute some conditional code.

// Syntax of Ternary Operator ( ? : ) is
// expression ? statement_1 : statement_2;

// expression: Condition to be evaluated.
// statement_1: Statement that will be executed if the expression evaluates to true.
// statement_2: Code to be executed if the expression evaluates to false.

// The above statement of the ternary operator is equivalent to the if-else statement given below:

// if ( expression ) {
//     statement1;
// }
// else {
//     statement2;
// }

#include<iostream>
using namespace std ;
int main()
{   
    // if(2>1){
    //     cout<<"yes";
    // }
    // else {
    //     cout<<"no";
    // }

    2>1? cout<<"yes": cout<<"no";



    cout<<endl;


    // int x;
    // if(2>1){
    //     x=1;
    // }
    // else {
    //     x=5;
    // }

    int x= 2>1? 1 : 5 ;
    cout<<x;


return 0;
}