#include<iostream> // characters include-Uppercase Alphabets ,Digits,Special Characters,White Spaces
using namespace std ;
int main()
{
    char ch[50];

    ch[0]='a';
    
    // ek ek element ko print kar skte par...poore array ko bhi kar skte ek saath cout se
    cout<<ch;

     cout<<endl<<endl;

    char chh[]={'a',' ','b','\n','c'};

   
    cout<<chh;

    char chhh[]="a\tb";            // ek saath lene mein last mein null character lagjata

    cout<<endl<<endl;

    cout<<chhh;
return 0;
}



// space : ' ' 
// tab : '\t'
//newline : '\n'



// ascii value- A:97 a:65 0:48