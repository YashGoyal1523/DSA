#include<iostream>       // rotate a square matrix by 90 deg clockwise
#include<vector>
using namespace std ;     // transpose then reverse each row
int main()
{
vector<int>v1;
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);
vector<int>v2;
v2.push_back(4);
v2.push_back(5);
v2.push_back(6);
vector<int>v3;
v3.push_back(7);
v3.push_back(8);
v3.push_back(9);

vector<vector<int> >v;
v.push_back(v1);
v.push_back(v2);
v.push_back(v3);


// printing original

for (int i = 0; i < v.size(); i++)
{
    for (int j = 0; j < v[i].size(); j++)
    {
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

// transpose

for (int i = 0; i < v.size(); i++)
{
    for (int j = i; j < v[i].size(); j++)
    {
        swap(v[i][j],v[j][i]);
    }
  
}


// reverse each row

for (int i = 0; i < v.size(); i++)
{
        reverse(v[i].begin(),v[i].end());
 }
  


cout<<endl;

// printing rotated

for (int i = 0; i < v.size(); i++)
{
    for (int j = 0; j < v[i].size(); j++)
    {
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}