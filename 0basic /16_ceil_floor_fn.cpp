// ceiling value of n  -  n if n is integer else n se aage wala phla integer ie bada phla  integer  - ceil(n) fn
// floor value of n  -  n if n is integer else n se piche wala phla integere ie chota phla  integer   -  floor(n) fn


#include<iostream>
#include<cmath> // for these fns
using namespace std ;
int main()
{
    float x=2.5;
    float n=-2.5;
cout<<ceil(x)<<" "<<floor(x)<<endl;
cout<<ceil(n)<<" "<<floor(n)<<endl;

//division
//ceil
cout<<ceil((float)5/2)<<endl;
//floor
//cout<<floor(5/2)<<endl;
cout<<5/2<<endl; //this gives floor value only

return 0;
}


// note:
//due to floating point errors in large nos... ceil((float)x/y) galat ans de skta
// -> ceil value of division of x and y ->  x+y-1/y

