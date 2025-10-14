//lc 342

//m1

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int x=log10(n)/log10(4);
        return pow(4,x)==n;
    }
};

//m2

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        float x=log10(n)/log10(4);
        return x==(int)x;
    }
};