// leetcode ques 204

//[0,n) mein primes btao

//bruteforce
// har element ke liye check kro ki prime h ya nhi normal method se and count maintain krte hue ....ek element ko check ke liye 2 se vaha tak every element check (naive approach) mein o(n^2), ya 2 se sqrt tak check mein o(n^3/2) : (tc zyada) :tle dega

// class Solution
// {
// public:
//     bool isPrime(int n)
//     {
//         if (n <= 1)
//             return false;
//         for (int i = 2; i < n; i++)  // note: if n=a*b then  1<=...a...<=sqrt(n)<=...b...<=n     // so note isko thoda optimise krne ke liye loop i<=sqrt(n) tak hi chalalo ....as uske baad  agar koi no se divisible hoga  toh uska other factor yaani jisse voh multiply hoke no banayega voh sqrt se phle mein hi aayega toh voh phle wale mein hi ans miljayega..... so vhi tak check kro kyuki agar phle hi nhi mila toh aage bhi nhi hi milega for sure
//         {
//             if (n % i == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     int countPrimes(int n)
//     {
//         int c = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (isPrime(i))
//             {
//                 ++c;
//             }
//         }
//         return c;
//     }
// }; // tle


// sieve of eratosthenes :   tc= o(nloglogn)

// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n==0 || n==1) return 0;

//         vector<bool>prime(n,true); //initially all are marked prime
//         prime[0]=prime[1]=false;

//         int ans=0;

//         for(int i=2;i<n;i++){
//             if(prime[i]){
//                 ans++;
//      mark its multiples as non-prime.
//                 int j=i*2;
//                 while(j<n){
//                     prime[j]=false;
//                     j+=i;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// agar n bhi incude krna hota toh n+1 ka banalete and <=n krlete
// sieve of eratosthenes is used for primes in 0 se n (1 se n, 2 se n bhi chal jayega vse ... same yhi uper wala chaljayega) 
// segmented sieve is used when prime are to be found in n1 se n2 (1<=n1,n2) (works in 1<=n1,n2 only)



