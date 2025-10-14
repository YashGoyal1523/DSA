#include<iostream>
#include<string.h> // for strlen()
using namespace std ;


int findlength(char ch[],int size){
// int count=0;
// for (int i = 0; i < size ; i++)
// {
//     if (ch[i]=='\0')
//     {
//         break;
//     }
//     else count++;
// }

int i=0;
int count=0;
while (ch[i]!='\0')
{
    count++;
    i++;
}

return count;
}


int main()
{
    char ch[50];
    cin.getline(ch,40);
    int length=findlength(ch,50);
    
    cout<<length;

cout<<endl;

    //alternate : strlen() function

    cout<<strlen(ch);
    
return 0;
}


// space , tab..... will take length 1