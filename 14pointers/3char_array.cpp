#include<iostream>
using namespace std ;
int main()              // sab concepts same h int array jse bas yeh cout ki functioning ke karan cout m alag hojata // any pointer pointing to base address ko cout krne pe array print hogaa
 
{
    char ch[]="yash";
    char*ptr=&ch[0] ; 
     
    cout<<ch<<endl; // here address wont get print ...whole char   array gets print
    cout<<&ch<<endl; 
    cout<<&ch[0]<<endl; // here address wont get print ...whole char   array gets print
    cout<<*ch<<endl; 
    cout<<ch+1<<endl;
    cout<<&ch[1]<<endl;

    cout<<ptr<<endl; // here address wont get print instead whole char array will get print
    cout<<&ptr<<endl; 
    cout<<*ptr<<endl;  
    



    // note 
    char*c="hello";  // possible but bad practice
    cout<<c;

    
return 0;
}

// Explanation
// Integer Arrays (int arr[]):

// When you pass arr (where arr is of type int[]) to cout, it decays to a pointer to its first element (int*).
// The cout operator interprets this pointer as a memory address and prints the address.
// Character Arrays (char ch[]):

// When you pass ch (where ch is of type char[]) to cout, it also decays to a pointer to its first element (char*).
// However, the cout operator is specifically overloaded to treat char* as a C-string, not just a pointer to a memory address.
// A C-string is a null-terminated array of characters, so cout will print the characters in the array up to the null terminator ('\0').