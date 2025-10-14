#include<iostream>
using namespace std ;

bool palindrome(char ch[],int n){
    int i=0;
    int j=n-1;

while (i<=j)
{
   if (ch[i]==ch[j])
   {
    i++;
    j--;
   }
   else return false;
}

return true;
}

int main()
{
    char ch[]="malayalam";
    int n=strlen(ch);
    bool ans=palindrome(ch,n);
    if (ans==false) 
    {
        cout<<" not";
    }
    else cout<<" yes";
return 0;
}