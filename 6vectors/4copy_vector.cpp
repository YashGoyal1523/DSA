#include<iostream>     
#include<vector>

using namespace std ;

int main()
{
    vector<int>v1(5,1);


 //m1
    vector<int>v2; // v2 vector created
    v2=v1;        // intitialising v2 //v2 becomes equal to v1 or   note: chahe initialy v2 kuch bhi ho ab usme v1 aagya toh ab v2 is same as v1 in sab kuch ..size cap..... in other words we can say...v1 copied to v2....//array mein nhi kar skte ese ek dusre ko
   
   //m2
    vector<int>v3=v1; 
    cout<<v3[0]<<endl;

    //m3
    vector<int>v4(v1);        
   
    // note
    vector<int>x(v1.begin(),v1.begin()+2);  //x created and  v1 ke given range ke elements (jse here phle do) dal gye x mein .......note: cap size jitni hi banegi abhi
    cout<<x.size()<<endl;

return 0;
}


// note vector<int> (v1.begin(),v1.begin()+2) ;   ... bina naam ka bhi bana skte ese