// a&b <= min(a,b)   
// a|b >= max(a,b)   

//1<<x = 2^x

//if a^b=c then a^c=b and b^c=a


// to multiply a no x by 2^k -> x<<k
// divide  -> x>>k



// to find x % 2^k of no -> x&((1<<k)-1)



//swap two nos x and y without temp variable -> x=x^y ; y=x^y ; x=x^y;



// no of set bits in a=x , no of set bits in b=y , no of set bits in a^b=z ->z is even if a+b is even and odd if odd



// if(x==a) x=b;
// else if(x==b) x=a ;    -> x=a^b^x;


//a+b=a^b+2(a&b)



//BUILTIN FUNCTIONS

//__builtin_popcount(x) : This function is used to count the number of set bits in an unsigned integer x. In other words, it counts the number of 1’s in the binary form of a positive integer.
// if the data type is of type long long -> __builtin_popcountll() 

//__builtin_clz(x) : count no of leading zeroes in unsigned int x
// long long -> __builtin_clzll(x)
//undefined for 0

//__builtin_ctz(x) : count no of leading zeroes in unsigned int x
//__builtin_ctzll(x) ->For unsigned long long
//undefined for 0

//__builtin_parity(x) : return parity for unsigned int x (0 for even no of 1s , 1 for odd no of 1s)
//__builtin_parityll(x) : For unsigned long long.



// tip : bitwise ques mein .... yeh bhi approach dimaag mein rkhna....0 se 31 tak loop chalana and bit by bit krna
//eg lc 1835


// Common conversions for CP
/*
    Quick 2^x ≈ 10^y Reference Table (log10(2) ≈ 0.30103)

    x     2^x (approx)          10^y form            Notes
    --------------------------------------------------------------
    10    1.024 × 10^3           ~ 10^3
    20    1.048 × 10^6           ~ 10^6              Bitmask n<=20 OK
    30    1.074 × 10^9           ~ 10^9
    31    2.147 × 10^9           INT_MAX + 1
    32    4.295 × 10^9           ~ 4 × 10^9
    40    1.099 × 10^12          ~ 10^12
    50    1.126 × 10^15          ~ 10^15
    60    1.153 × 10^18          ~ 10^18             ~LLONG_MAX/8
    63    9.223 × 10^18          LLONG_MAX
    64    1.844 × 10^19
    100   1.268 × 10^30          ~ 10^30
    128   3.403 × 10^38          ~ 10^38             float max ~3.4e38
    256   1.158 × 10^77          ~ 10^77
    512   1.341 × 10^154         ~ 10^154

    Trick:
    2^x ≈ 10^(0.30103 * x)
    → Multiply x by 0.3 for quick mental approximation.
*/
