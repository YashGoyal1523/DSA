// print wave form of matrix

// 1 2 3
// 4 5 6
// 7 8 9

// colwise wave form is : 1 4 7 8 5 2 3 6 9
// rowwise wave form is : 1 2 3 6 5 4 7 8 9

#include <iostream>
using namespace std;

void waveCol(vector<vector<int> > v)
{

    // even col index m toptodown jaare and odd col index m downtotop jaare

    int m = v.size();
    int n = v[0].size();

    for (int Col = 0; Col < n; Col++)
    {
        
        if ((Col & 1) == 0) // even no of col -> Top to bottom.
        {
            for (int Row = 0; Row < m; Row++)
            {
                cout << v[Row][Col] << " ";
            }
        }
        else     // odd no of col -> Bottom to top.
        {
            
            for (int Row = m - 1; Row >= 0; Row--)
            {
                cout << v[Row][Col] << " ";
            }
        }
    }
}

void waveRow(vector<vector<int> > v)
{

    // even row index m lefttoright jaare and odd row index m rightoleft jaare

    int m = v.size();
    int n = v[0].size();
    for (int Row = 0; Row < m; Row++)
    {
        
        if ((Row & 1) == 0) // even no of row -> left to right
        {
            for (int Col = 0; Col < n; Col++)
            {
                cout << v[Row][Col] << " ";
            }
        }
        else     // odd no of row -> right to left
        {
            
            for (int Col = n - 1; Col >= 0; Col--)
            {
                cout << v[Row][Col] << " ";
            }
        }
    }
}



int main()
{
    vector<vector<int> > v; // 2D vector v created

    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vector<int> vec2;
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);

    vector<int> vec3;
    vec3.push_back(7);
    vec3.push_back(8);
    vec3.push_back(9);

    v.push_back(vec1);
    v.push_back(vec2);
    v.push_back(vec3);

    waveCol(v);
    cout<<endl;
    waveRow(v);

    return 0;
}


