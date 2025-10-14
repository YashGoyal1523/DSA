// given a string. print the frequency of each letter in it

// hashing by using map
#include<iostream>
#include<unordered_map>
using namespace std ;



int main()
{
    string st="yashgoyal";

 //precompute
    unordered_map<char,int>mapp;
    for(int i=0;i<st.length();i++){
        char ch=st[i];
        mapp[ch]++;            // ek ch ke liye........ for first time ie phle se us ch ki key nhi bani h  tab iska mtlb hoga ...ch key create hogi with value zero and fir uski value +1 hogyi ..... usi ch ke liye second time mein ie key phle se hai toh value +1 hojayegi 
    }

    //fetch
    for(auto i :mapp){
        cout<<i.first<<"->"<<i.second<<endl;
    }
return 0;
}




// prefer unordered for less tc.... if it shows tle then switch to ordered .....sorted key m maanga ho fir toh ordered hi lelena