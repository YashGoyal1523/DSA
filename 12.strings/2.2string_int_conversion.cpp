

#include<iostream>
#include<string>
using namespace std ;
int main()
{


    // int to string conversion

    int x=1;
    string s=to_string(x);        // to_string() fn : The to_string() function can be used to convert an int, floating point values, or any number to a string.
    cout<<s<<endl;

    cout<<to_string(55)<<endl;

    // note:
    string a=to_string(1);
    string b=to_string(2);
    cout<<a+"->"+b<<endl;

    
    // string to int conversion

    string st="-12.34";
    int num=stoi(st);    // stoi() fn takes a string as an argument and returns its value in int form  // syntax : stoi(str,position,base) : str- string to be converted(compulsory) , position- starting position(optional with default value = 0) ,base- base of the number system(optional with default value = 10)

    cout<<num<<endl;

// similarly stoll ...string to long long

return 0;
}



// //note: manually doing string to int conversion 

// string s="123";
// int num=0;
// for(int i=0;i<s.size();i++){
//     num=num*10+(s[i]-'0');
// }
// cout<<num;

// or

// string s="123";
// int num=0;
// int x=0;
// for(int i=s.size()-1;i>=0;i--){
//   num+=(pow(10,x)*(s[i]-'0'));
//    x++;
// }
// cout<<num;

