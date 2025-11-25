
// given binary no

// string bin="10101"

//convert to decimal no

//m1 left to right traverse
//m1.1
int n=bin.size();
int power=n-1;
int dec=0;
for(int i=0;i<n;i++){
    dec+=pow(2,power)*bin[i];
    power--;
}
return dec;

//m1.2 bit manipulation
    int n=bin.size();
    int dec = 0;
    for (int i=0;i<n;i++) {
        dec = (dec << 1) | bin[i];   //or   dec = (dec*2) | bin[i];  or dec = (dec*2) + bin[i];    
    }
    return dec;


//m2 right to left traverse

int n=bin.size();
int dec = 0;
int base = 1;
for (int i = n - 1; i >= 0; --i) {
    dec += bin[i] * base;  
    base=base*2; //base=base<<1;     // multiply base by 2
}
return dec;

