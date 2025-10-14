// info - decimal no is 0 indexed from right...rightmost bit is 0 index and so on leftwards


#include<iostream>
#include<cmath>   // for pow() function
using namespace std ;

// method- ek ek krke piche(right) se bits nikalte rhege  and form krte rhege

//division method to get bits 

// n%2 will give last bit in binary form of n
// n/2 will give result with last bit removed (now second last wala is last ie zero indexed and so on)
int method1(int n){
    
    int binary=0;

    int i=0;
    while (n>0)
    {
        int bit=n%2; // last bit      //first iteration mein sabse right wala milgya ie lsb fir aglo mein left left aate jaayege till msb
         binary=bit*pow(10,i)+binary;  //first iterztion ie last bit ko 10^0 se ..second iteration ie second last ko 10^1 se ...so on... multiply and add all     // getting a number in which uper wale step se first obtained bit iska sabse right digit  fir agle obtained leftwards ese present h .....ie number ke digits(right to left) are the bits ( msb to lsb)(right to left) of binary form ...... // overall the number is representing binary form  // yaha i likhke agli mein i++ likhna bhi ek hi baat...note: agli line m likhre toh ++i bhi likh skte par yaha ++i nhi likh skte
        n=n/2;   // remove last bit
        i++;
        
    }


// another way to write

// int i=1;
//     while (n>0)
//     {
//         int bit=n%2; 
//          binary=bit*i+binary;     
//         n=n/2;  
//         i=i*10;
        
//     }



    return binary;
}




// bitwise method to get bits

//bitwise & and right shift will be used

//note kisi binary no ko & krege with 1 toh uska last bit ki value will be resultant 
//note int x=5&1 will give ans 1 as last bit of 5 ie 101 is 1 and usko decimal m convert is 1

//note kisi binary no ka right shift 1  will give result which is equal to that no with last bit removed (now second last wala is last ie zero indexed and so on)
int method2(int n){

int binary=0;
    int i=0;
    while (n>0)
    {   int bit=n&1;  // first iteration mein sabse right bit milgya
        binary=bit*pow(10,i++)+binary;               
        n=n>>1;
}
return binary;
}


int main()
{
    int n;
    cout<<"enter number";
    cin>>n;
int ans=method1(n);
cout<<ans;
return 0;
}




// tip: do alag dabbe same naam ke ho skte lekin alag alag block of code mein yaani  alag alag brackets {} mein aur unn dabbos ki accesibltites inside that brackets hi hoge ...note for ka( ) ya if ka ( ) ko bhi include krte unke block of code mein