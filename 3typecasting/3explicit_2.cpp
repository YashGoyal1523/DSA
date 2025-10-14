// note :  int/int=int , int/float=float(typeconversion) , float/int=float , float/float=float


// application of explicit

#include<iostream>
using namespace std ;
int main()
{   
    int a=10;
    int b=3;

    float c=10;
    float d=3;

    // a/b will be 10/3=3  , c/d will be 10.0/3.0= 3.333

    // to get a/b as 3.3..  a ya b ya dono ko explicitly float banado 

// ek ko krna wala dekhte
// note: store float m hi krnaaa vrna typeconversion hojayegi ;)
    float f=a/((float)b); // first b converted from int to float ...now int/float...so num convert from int to float (implicit) so now float by float....resultant float......so now.storing float in float ...float will be stored ......so will give 3.333
      cout<<f<<endl;
return 0;
}



