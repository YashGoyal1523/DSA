#include<iostream>
using namespace std ;
int main()
{
    char ch[5];


    //  ek ek element input ya print kar skte but direct pure ko bhi kar skte

    // cin>>ch;
    // cout<<ch;

    // note ek ek lene m last mein null character nhi ata par ek saath lene m aajata hai 

    // cin dwara ek saath input lene m space,tab,enter(newline) aate hi ruk jaayega
    // iska upaay hai cin.getline(name of array,size of input)...yeh space ,tab read kr skta
    cin.getline(ch,10);
     cout<<ch;
return 0;
}

// null character : '\0' : signifies termination of string(collection of characters ) , has ascii value 0
