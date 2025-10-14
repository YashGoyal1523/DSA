#include<iostream>
#include<string.h>
using namespace std ;

void reverse(char ch[],int n){
    int i=0;
    int j=n-1;

while (i<=j)
{
    swap(ch[i],ch[j]);
    i++;
    j--;
}
}

int main()
{
    char ch[10]="hel lo";
    int length=strlen(ch);
    reverse(ch,length);     // pass by ref like int array
    
    cout<<ch;
return 0;
} 