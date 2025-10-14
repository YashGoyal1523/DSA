// remove(clear) rightmost set bit 

// mask(lsb se rightmost 1 bit ke phle tak ke bits 1 and rightmost ke corr 0 and baaki bits same) ka and krdo 

// yeh mask banjayega n-1 krke....so n & (n-1) krna

#include<iostream>
using namespace std ;
int main()
{
 int n=12;
 int mask=n-1;
 int ans=n&mask;
 cout<<mask;
return 0;
}