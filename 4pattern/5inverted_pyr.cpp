#include<iostream>
using namespace std ;
int main()
{

    // 5 rows 
for (int i = 0; i < 5; i++)        //row
{
    for (int j = 0; j<5-i; j++)        // column    
    {
        cout<<"* ";
    }
    cout<<endl;
}



return 0;
}