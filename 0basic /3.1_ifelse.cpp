// if(cond){             // if cond is true then 'if' gets executed otherwise ie if its false then 'else' gets executed

// }
// else{
    
// }




#include<iostream>
using namespace std;
int main()
{
   int n;
   cout<<"enter n ";
   cin>>n;

if(n>0)
{
   cout<<"pos";
}
else if (n<0)
{
    cout<<"neg";
}
else
{
    cout<<"zero";

}




return 0;
}


// // note: 
 
// if(cond1){
//     if(cond2){         

//     }
// }
// else{

// }

// is not same as

// if(cond1 && cond2){

// }
// else{

// }

// as uss case m jab cond1 satisfy ho and cond2 nhi tab first mein outer if mein hi ghus ke andar rukege fir else ke aage chale jaayege and  else noi chalega par second m if mein na ghuske else chal jaayega




// // note:

// if(cond1&&cond2){} :  phle cond1 check hoti fir cond2. if cond1 false aajaye fir cond2 check nhi hoti and seedha if se nikaljate (short circuiting) . if true ajaye fir check hoti h cond2 and voh trrue toh if execute and false toh exit
// if(cond1||cond2){} : phle cond1 check hoti h fir cond2 . if cond1 true aajaye fir cond2 check nhi hoti and seedha if execute (short circuiting). if false aajaye fir cond2 check hoti and agar voh true toh execute and false toh exit.




// // note:  

//         int a;
//         if((a*a)==4){                // idhar a*a bhi usi datatype ka consider hoga jo a ka h toh iski accepted range bhi vhi hogi jo a ke datatype ki hai..........agar a*a out of range of a ka datatype gaya toh error dega
//             return true;
//         }




// // note

//  if(boolean){ ... } : executed if the boolean variable is true  : If the boolean variable is true, the condition inside the if statement evaluates to true, and the block of code within the braces { ... } is executed. If the boolean variable is false, the condition evaluates to false, and the block of code is skipped.

// bool a;
// if(a){     is same as         if(a==true){      is same as    if(a!=false){

// }                                    }                               }


// non zero integers are considered true , 0 is considered false in boolean extract
//  if(integer) { ... } : executed if the integer variable integer is non zero integer : If integer is non-zero, the condition inside the if statement evaluates to true, and the block of code within the braces { ... } is executed. If integer is zero, the condition evaluates to false, and the block of code is skipped.

// int a;
// if(a){     is same as         if(a!=0){

// }                                  }

// similarly float -(a!=0.0).... etc....


// non null pointers are considered true and null pointer as false in boolean extract
//  if(pointer) { ... } : executed if the pointer is non null pointer : If the pointer is non null  (i.e. it points to a valid memory address), the condition inside the if statement evaluates to true, and the block of code within the braces { ... } is executed. If the pointer is null (i.e., it does not point to any memory address), the condition evaluates to false, and the block of code is skipped.

// int *a;
// if(a){       is same as           if(a!=NULL){

// }                                   }

// ETC...

// note

// int a;
// if(a && cond2){

// }     // ese bhi likh skte     which will be same as      int a;
//                                                        if(a!=0 && cond2){

//                                                              }

// ya fir 
// int a,b;
// if(a && b){

// }   // ese bhi kr skte


// note

// ! reverses the result obtained 

//  if(!integer){ } : executed if the integer value is zero : If the integer is zero (0), !integer evaluates to true and code executed.If the integer is any non-zero value, !integer evaluates to false.and code skipped

// int a;
// if(!a){     is same as         if(a==0){

// }                                    }

// ETC...