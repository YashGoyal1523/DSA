// making kth bit from right in binary form of a given decimal no  equal to 1 ie setting the kth it from right and returning updated decimal no

// note righmost bit is said to be zeroth bit then leftwards 1st 2nd and so on   ie 0 indexing from right




//concepts used 
//note 1<<k (1 ka left shift k times) becomes 1000...ktimes zero

// 1|1 is 1 , 1|0 is 1  ,0|0 is 0   (bitwise or)

// plan : jis bit ko set karna uss bit ka 1 se bitwise or krdo

// eg set the second bit from right in decimal no 11

// here we need to set 1011 mein right se 2nd yaani 0 wali bit ....toh hum krege 1 ko left shift 2 baar jisse we get 100 ab iska or krdege with 1011 (masking method ) ...hence jis bit ko set krna uske niche 1 aajayega baakio ke zero so no change so sab satisfied....
// we observe agar kth set krna h toh 1 ko k left shift krke or krdo 

#include<iostream>
using namespace std ;


int set2nd(int n){
    int x=1<<2;
    int y=n|x;
    return y;

}


int main()
{
    int n=11;
    int ans=set2nd(n);
    cout<<ans;
return 0;
}



// 11 is 1011...setting ke baad become 1111 which is 15


// note agar rightmost ko zeroth ki jagah 1st hi lete toh...agar kth ko set krna hota toh 1 ko k-1 shift krte....