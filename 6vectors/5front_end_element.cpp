#include<iostream>
#include<vector> 
using namespace std ;
int main()
{
    vector<char>v(5,'a');
    v.push_back('d');

    cout<<"front element: "<<v[0]<<endl;
     cout<<"front element: "<<v.front()<<endl;
     cout<<"end element: "<<v[v.size()-1]<<endl;
     cout<<"end element: "<<v.back()<<endl;

return 0;
}