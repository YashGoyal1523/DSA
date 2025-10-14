#include<iostream>
using namespace std ;
int main()
{   int i=0;

    while (i<3)
    {
        int x = 1 ;
        cout<<&x<<endl;
        i++;
    } 
    // isme int dabba overwrite hori hai..... usi int ke dabbe par new value aari

    int j=0;
    while (j<3)
    {
        int* y = new int(1) ;
        cout<<y<<endl;
        j++;
    } 
    
    // isme pointer dabba overwrite hora hai and int ke dabbe naye banre hai  .... ussi pointer par address stored change hora hai ...purane dabbe se hatke nye dabbe ko point krra
return 0;
}