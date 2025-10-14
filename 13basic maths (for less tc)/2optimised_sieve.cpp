// primes in [0,n]

// optimised sieve of erathosthenes


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// normal
vector<bool> Sieve(int n)
{
    // create a sieve array telling isPrime till 'n'
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= n; i++)
 
    {
        if (sieve[i] == true)
        { // means, sieve[i] is Prime and mark its multiples as non-prime.
           
            int j = i * 2; 
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;


    
}



// optimised

vector<bool> Sieveoptimised(int n)
{
    // create a sieve array telling isPrime till 'n'
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    //for (int i = 2; i <= n; i++)
    for (int i = 2; i * i <= n; i++) // or i<=sqrt(n) 
                                    // Optimisation 2: (Outer loop):
                                     // if i becomes > sqrt(n), then the
                                     // inner loop does not work.
    {
        if (sieve[i] == true)
        {
            // means, sieve[i] is Prime and mark its multiples as non-prime.

            //int j = i * 2;
            int j = i * i; // Optimisation 1 (inner loop):
                           // first unmarked number would be i*i
                           // as, other have been marked by 2 to (i - 1).
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;  // tc= o(nloglogn)  worst case m (same to normal).....par generally kisi case m better hi hogi hi normal wale se
}

int main()
{
    int n = 11;
    vector<bool> sieve = Sieveoptimised(n);
    // print all primes
    for (int i = 0; i <= n; ++i)
    {
        if (sieve[i])
            cout << i << " ";
    }
    cout << endl;

    
    return 0;
}
