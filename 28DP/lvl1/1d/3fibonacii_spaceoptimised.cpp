//  tabulation mein space optimisation

// find f(n)


// tabulation mein patterns observe krke space optimise krdo

// like here dp[index] depends on dp[index-1] and dp[index-2] .....pattern is formimg ie required ans is obtained from its previous two element ans



#include<iostream>
using namespace std ;

int spaceopt(int n){
    //1.,2.
    int preprev=0;   // initially represent 0 index of dp ...ans pata hai 0
    int prev=1;    // initially represent 1 index ... ans pata h 1
     if(n==0) return preprev;
     if(n==1) return prev;             // yeh dono cases alag se likhne pdege...alag se handle
    int curr;
    //3.
    for (int i = 2; i <=n; i++)
    {
        curr=prev+preprev;
        //shift
        preprev=prev;
        prev=curr;
    }
    return curr;  
}

int main()
{ int n;
    cin>>n;
    int ans=spaceopt(n);
    cout<<ans;

return 0;
}



//tip: space opt fn k liye tabu fn ko copy paste krke chages krlo -> fn name change , creation initialisation of dp array m change , loop ke  andar dp array m change  ,shift kro, return m dp array change    
// tip: return mein : agar curr hi saaari req position ko cover krra toh last m curr hi return , agar curr se dusra variable initial m ek starting wali req pos leleta and curr ek position aage se shuru , toh voh dusra variale return kro ya voh dusre wale ki pos alag se handle and return curr, agar curr se dusre variable startring ki do req position lelete toh voh dono pos ko alag se handle and return curr ...ya fir starting se phli pos ko alag se handle and return dusri pos wala 