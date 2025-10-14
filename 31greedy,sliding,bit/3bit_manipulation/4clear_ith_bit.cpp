// clear(make 0) ith bit

// masking
// m1 mask wale(sab zero,ith wala 1) se xor krdo
//1<<i se banjayega

//  mask wala(sab 1,ith wala 0) se & krdo - yeh wla mask banane ke liye ..... ~(1<<i) se hojayega
// initially voh bit 0 ho ya 1 dono case sambhal jaayeege  and finally 0 hi milega
// lets do second wale se
#include <iostream>
using namespace std;

void clearIthBit(int n, int i)
{
    int mask = ~(1 << i);
    n = n&mask;
    cout<< "Updated number: " << n ;
}
int main()
{
    int n = 10;
    int i = 1;
    clearIthBit(n, i);

    return 0;
} 