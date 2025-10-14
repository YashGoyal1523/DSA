#include<iostream>
using namespace std ;

void print(){
    int x=1;
    cout<<&x<<endl;
    print();
}
// diff func ke dabbe diff hote hai and can have same name 
// recursion mein new dabbes bante har baar,as dobara function hi call hora , no overwrite

int main()
{
    print();
return 0;
}