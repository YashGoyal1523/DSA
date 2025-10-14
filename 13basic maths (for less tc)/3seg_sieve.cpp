// find primes bw n1 to n2 (1<=n1,n2)

//[n1,n2] mein batao

// m1 : normal seive se 0 se n2 tak ka sieve array  banalo...fir n1 se n2 ke bich wale ginlo.....acha method nhi for n2 badaaaaa toh usme seive size bada hojayega dikkat dega


// m2 : segmented sieve (1<=n1,n2 mein hi work krta)

// we have n2-n1+1 numbers jinme check krna :n2-n1+1  size ka sieve banayege (n2-n1+1 indexes banjayege) and sabko true mark krlo ( n1 ke liye 0 index lege ...n1+1 ke liye 1 lege.......n2 ke liye n2-n1  index(last) lege )
// and iss seg sieve array m true false wala khelege
// normal sieve use  krke 0 se sqrt(n2) tak ke primes nikal lo
// we will use them to mark non primes in seg seive
// ek ek ko uthao and uske saare multiples occuring in seg sieve ko non prime mark krlo..
//esa krne k liye x ko uske phle multiple occuring in seg sieve par rkhdo...fir uss multiple ko  and vaha se sab multiples ko non prime mark krlo...(to find phla multiple of x in seg sieve do : (n1/x)*x : agar isse <n1 mein aaye toh jo aayeaga usme +x krlena)
// note thoda optimise krne k liye start  max(first multiple,x*x ) se krege as ho skta first multiple phle hi mark ho chuka ho kya pata (normal sieve ki optimisation 1 jsa)


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> Sieveopt(int n)
{
    
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

 
    for (int i = 2; i * i <= n; i++) 
    {
        if (sieve[i] == true)
        {
           
            int j = i * i; 
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

vector<bool> segmentedSeive(int L, int R)
{
   // base primes nikal lete
    vector<bool> sieve = Sieveopt(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
            basePrimes.push_back(i);
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1)     
    {
        segSieve[0] = false;
    }

    for (auto prime : basePrimes)
    {
        int first_mul = (L / prime) * prime;
        first_mul = first_mul < L ? first_mul + prime : first_mul;
        int j = max(first_mul, prime * prime);
        while (j <= R)
        {
            segSieve[j - L] = false;   // L ko 0 index , L+1 ko 1 index.....so on
            j += prime;
        }
    }
    return segSieve;
}

int main()
{
    
    int L = 110;
    int R = 130;
    vector<bool> segsieve = segmentedSeive(L, R);
    for (int i = 0; i < segsieve.size(); ++i)
    {
        if (segsieve[i])
            cout << L + i << " ";
    }
    cout << endl;
    return 0;
}


// try ques : product of primes : gfg : https://www.geeksforgeeks.org/problems/product-of-primes5328/1


// class Solution
// {
// public:

// #define M 1000000007

//     vector<bool> Sieve(long long int n)
//     {
        
//         vector<bool> sieve(n + 1, true);
//         sieve[0] = sieve[1] = false;

//         for (long long int i = 2; i * i <= n; i++) 
//         {
//             if (sieve[i] == true)
//             {
               
//                 long long int j = i * i; 
//                 while (j <= n)
//                 {
//                     sieve[j] = false;
//                     j += i;
//                 }
//             }
//         }
//         return sieve;
//     }

//     vector<bool> segmentedSeive(long long int L, long long int R)
//     {
        
//         vector<bool> sieve = Sieve(sqrt(R));
//         vector<long long int> basePrimes;
//         for (long long int i = 0; i < sieve.size(); i++)
//         {
//             if (sieve[i])
//                 basePrimes.push_back(i);
//         }

//         vector<bool> segSieve(R - L + 1, true);
//         if (L == 1)
//         {
//             segSieve[0] = false;
//         }

//         for (auto prime : basePrimes)
//         {
//             long long int first_mul = (L / prime) * prime;
//             first_mul = first_mul < L ? first_mul + prime : first_mul;
//             long long int j = max(first_mul, prime * prime);
//             while (j <= R)
//             {
//                 segSieve[j - L] = false;
//                 j += prime;
//             }
//         }
//         return segSieve;
//     }

//     long long primeProduct(long long L, long long R)
//     {
//         vector<bool> segSieve = segmentedSeive(L, R);
//         long long int ans = 1;
//         for (long long int i = 0; i < segSieve.size(); i++)
//         {
//             if (segSieve[i])
//             {
//                 long long int actualPrime = (L + i) % M;
//                 ans = (ans * actualPrime) % M;
//             }
//         }
//         return ans;
//     }
// };