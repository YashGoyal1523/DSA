#include<iostream>      // (done by programmer)
using namespace std ;
int main()
{
//double to int
double pi=3.1415;
int pii=(int)pi; // explicit conversion of pi from double to int
int piii=(int)3.1415;
cout<<pii<<endl<<piii<<endl;

char p=(int)3.1415; // explicit of 3.1414 to int then resultant ka implicit from int to char as char m store hora

// int to char
int x=97;
char ch=(char)x; // explicit conversion of x from int to char .... note ascii valuee ke acc changes hojate

// float to char
float a=65.36;
char val=(char)a;// explicit conv of a from float to char....note: as char corresponds to  ascii values which are integer ..toh float ka decimal part disregard hojata and only integer dekhtee.....so here conversion of 65 to a

  // operation
    float a=2.2;
    int b=4;
    int c=(int)a+b;    // explicit conversion of a from float to int ...ie from 2.2 to 2.(note ab same datatype hogye toh koi dikkat noi operaation mein)......b remains int ....// explicit nhi krte toh same datatype krne ke liye phle b ka int to float hota(implicit) 
    cout<<c;

    
return 0;
}

// similarly all other can be done.....




// note:  char('a'+1) : phle andar char ka implicit char to int fir resultant int ka explicit int to char