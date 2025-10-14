#include<iostream>  // replace @ with space
using namespace std ;

void replace(char ch[]){
    int i=0;
    while (ch[i]!='\0')
    {
        if (ch[i]=='@')
        {
            ch[i]=' ';
        }
        i++;
    }
    
}




int main()
{
    char ch[]="My@Name@is@Yash";
    replace(ch);

    cout<<ch;
return 0;
}