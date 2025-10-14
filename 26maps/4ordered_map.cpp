#include<iostream>
#include<map> // ordered map
using namespace std ;
int main()
{
    map<char,int>mapp;
return 0;
}


// ordered map mein sorted order of keys mein store hote 


// unordered mein key can be individual datatype only whereas in ordered map the key can be individual datatypes or a pair datastructure or other data structures which satisfy  requirements : They must be comparable.They must follow a strict weak ordering criterion.However, it's possible to use custom comparison functions or provide custom comparators to handle more complex data structures(like vector)

// eg agar key is a pair datatype toh unordered map nhi le skte and only ordered possible .....map<pair,x> 

// prefer unordered for less tc.... if it shows tle then switch to ordered .....sorted key m maanga ho fir toh ordered hi lelena