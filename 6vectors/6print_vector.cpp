#include<iostream>
#include<vector>
using namespace std ;
int main()
{

vector<int>v;
v.push_back(1);
v.push_back(2);
    
// method 1

// int size=v.size();

//     for (int i = 0; i < size; i++)
//     {
//        cout<<v[i]<<" ";
//     }

// method 2

// for(int vec:v){          

//     cout<<vec<<" ";
// }

// method 3 using iterator

vector<int>::iterator it=v.begin();

while(it!=v.end()){
    cout<<*it<<" ";
    it++;
}

 return 0;
}



