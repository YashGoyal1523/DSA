
// convert elements of given ch array to uppercase if its lower
#include<iostream>
using namespace std ;

void convert(char ch[]){
    int i=0;
    while(ch[i]!='\0'){
        // check whether lowercase or not...if lower then convert
        if (ch[i]>='a'&&ch[i]<='z')  // >=97 <=122 bhi kr skte
        {// lower hai
            ch[i]=ch[i]-'a'+'A';
        }
        i++;
    }
    
}

int main()
{
    char ch[]="hello yash how r u";
    convert(ch); 
    cout<<ch;
return 0;
}

// toupper() fn : comverts to upper case

// for upper to lower ....   >='A' && <='Z'   and  -'A'+'a'; 

// tolower() fn : converts to lower case 
