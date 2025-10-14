#include<iostream>
#include<vector>
using namespace std ;
int main()
{   
    
     //method

    vector<vector<int> >v(5,vector<int>(10,0));    // v naam ka 2d vector with 5 rows and  each row mein 10 columns and each element valued 0 
                                                    // int wale > ke baad space needed fir > aayega

// row size is given by vector ka size.... v.size() and col ka size is given by row  ka size ... v[row index].sixe()

    int rowsize=v.size();
    int colsize=v[0].size();   // 1st row mein no of columns


    // printing
    for (int i = 0; i <v.size(); i++)    // rows
    {
       for (int j = 0; j <v[i].size(); j++)   // columns
       {
       cout<<v[i][j]<<" ";
       }
       cout<<endl;
    }



        cout<<endl;

    //method

    vector<vector<int> >v1; // 2D vector v1 created
    
    vector<int>vec1(5,1);
    vector<int>vec2(6,2);
    vector<int>vec3(3,1);
    vector<int>vec4(7,8);


    v1.push_back(vec1);
    v1.push_back(vec2);
    v1.push_back(vec3);
    v1.push_back(vec4);


    // printing
    for (int i = 0; i <v1.size(); i++)
    {
       for (int j = 0; j <v1[i].size(); j++)
       {
       cout<<v1[i][j]<<" ";
       }
       cout<<endl;
    }
   
   // method
   vector<vector<int> > v2(5); // 5 rows ka 2d vector created
   v2[0].push_back(5);

   
return 0;
}

// note: input se banana

// vector<vector<int>> v;
//   int n;
//   cout << "Enter size: ";
//   cin >> n;
//   for (int i = 0; i < n; ++i) {
//     int a, b;
//     cout << "enter a, b" << endl;
//     cin >> a >> b;
//     vector<int> temp;
//     temp.push_back(a);
//     temp.push_back(b);
//     v.push_back(temp);
//   }


 // jagged vector: alag alag row m alag alag no of columns ho