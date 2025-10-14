#include<iostream>
#include<vector>
using namespace std ;
                                        // call by reference using reference vector
void byref(vector<int>&v){
    v.push_back(2);
    return;
}


int main()
{
vector<int>v(5,1);

byref(v);

cout<<v.size();

return 0;
}

