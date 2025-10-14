//to get sum of any submatrix of a 2d matrix


// https://youtu.be/WibxoqMSMCw?si=xjtJwG95gSRrM4qW


// method - prefix sum in 2d matrix


// arr:          pre:
//  _ _ _         _ _ _
// |1 0 1        |1 0 2
// |0 1 0    ->  |1 2 3  
// |1 1 1        |2 4 6

// pre[i][j] -> sum of submatrix in arr from top left (0,0) to bottom right (i,j) 

// pre[i][j] = arr[i][j]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]

//sum of submatrix with top left (a,b) and bottom right (c,d):
//sum((a,b),(c,d))=pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1]


#include <bits/stdc++.h>
using namespace std;

// Build prefix sum matrix
vector<vector<int>> buildPrefix(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> pre(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i][j] = arr[i][j];
            if (i > 0) pre[i][j] += pre[i - 1][j];
            if (j > 0) pre[i][j] += pre[i][j - 1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i - 1][j - 1];
        }
    }
    return pre;
}

// Query sum of submatrix from (a,b) to (c,d) inclusive
int getSum(vector<vector<int>> &pre, int a, int b, int c, int d) {
    int sum = pre[c][d];
    if (a > 0) sum -= pre[a - 1][d];
    if (b > 0) sum -= pre[c][b - 1];
    if (a > 0 && b > 0) sum += pre[a - 1][b - 1];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;  
    cin >> n >> m; // matrix size
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<int>> pre = buildPrefix(arr);

    int q; 
    cin >> q; // number of queries
    while (q--) {
        int a, b, c, d; // top-left (a,b), bottom-right (c,d)
        cin >> a >> b >> c >> d;
        cout << getSum(pre, a, b, c, d) << "\n";
    }

    return 0;
}

//note: yeh calculation ke time conditions a>0,b>0..etc. na daalni padi uske liye ese kr skte
//add padding row and col in pre array
// pre becomes 1 based index

// arr:          pre:
//             0 0 0 0 
// 1 0 1       0 1 0 2
// 0 1 0    -> 0 1 2 3  
// 1 1 1       0 2 4 6

// pre[i][j] -> sum of submatrix in arr from top left (0,0) to bottom right (i-1,j-1) 

// pre[i][j] = arr[i-1][j-1]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]
//sum((a,b),(c,d))= pre[c+1][d+1] - pre[c+1][b]- pre[a][d+1]  + pre[a][b]
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildPrefix(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = arr[i-1][j-1] 
                        + pre[i-1][j] 
                        + pre[i][j-1] 
                        - pre[i-1][j-1];
        }
    }
    return pre;
}

int getSum(vector<vector<int>> &pre, int a, int b, int c, int d) {
    return pre[c+1][d+1] - pre[a][d+1] - pre[c+1][b] + pre[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;  
    cin >> n >> m; // matrix size

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    auto pre = buildPrefix(arr);

    int q; 
    cin >> q;
    while (q--) {
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        cout << getSum(pre, a, b, c, d) << "\n";
    }
}
