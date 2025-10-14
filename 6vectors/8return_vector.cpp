// function can be made with return type as vector       (array noi)
#include<iostream>
#include<vector>
using namespace std ;



vector<int> func(){

    vector<int>v2;
    v2.push_back(1);

    return v2;

}
int main()
{
vector<int>v(5,1);

vector<int>v1=func();

cout<<v1[0];


return 0;
}