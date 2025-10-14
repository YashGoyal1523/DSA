// update ith bit 
 
// we will be given- no. , i and will be given target value ie whether to set it(make 1) or clear it(make 0)

//pichle set clear ke codes  and if else use krke kar skte ...ki agar set krna h toh yeh else yeh ese  kar skte par
// ek hi m dono krte h

// method - ith bit ko phle clear krlo, fir uska | krdo mask (sab zero , ith par jo target h voh ie 1 if set and 0 if clear )



#include <iostream>
using namespace std;

void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n&mask;
}

void updateIthBit(int n, int i,int target) {
clearIthBit(n,i);
int mask = (target<<i);
n = n | mask;
cout << "Updated number: "<< n << endl;
}
int main()
{
    int n = 10;
    int i = 3;
    int target=0;
    updateIthBit(n, i,target);

    return 0;
} 