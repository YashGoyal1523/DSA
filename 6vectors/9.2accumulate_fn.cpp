
// accumulate() fn : <numeric> header file

//  accumulate(firstpos, lastpos, sum);  : returns sum between [first,last) with initial sum equal to 'sum'

#include<iostream>
#include<numeric>
using namespace std ;
int main()
{
    vector<int>v(5,1);
    int sum=accumulate(v.begin(),v.end(),0);
    cout<<sum;
return 0;
}