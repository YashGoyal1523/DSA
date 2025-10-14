//->permutation of n elements is an arrangement of n elements valued 1 to n

//  given array containing permutation of n elements , find min swaps needed to sort array
//  this can be seen as
//  if given 0 based indexed array -> given array containing permutation of n elements , find min swaps needed to rearrange elements such that 1 is at index 0 , 2 is at 1 , .....
//  if given 1 based indexed array -> given array containing permutation of n elements , find min swaps needed to rearrange elements such that 1 is at index 1 , 2 is at 2 , .....


//To sort a cycle of length k, you need exactly k - 1 swaps.
// ans= sum of all (cycle length - 1) = n-no of cycles


//m1

//tarika 1
//ans= sum of all (cycle length - 1)

// 0 based indexing

#include <bits/stdc++.h>
using namespace std;


int minSwapsPermutation(vector<int>& a) {
    int n = (int)a.size();
    vector<char> vis(n, 0);
    long long swaps = 0;

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int cur = i;
        int len = 0;
        // follow the cycle: index i -> value a[i] should be at position a[i]-1
        while (!vis[cur]) {
            vis[cur] = 1;
            cur = a[cur] - 1; 
            ++len;
        }
         swaps += (len - 1);
    }
    return swaps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << minSwapsPermutation(a) << "\n";
    return 0;
}


//1 based indexing

#include <bits/stdc++.h>
using namespace std;


int minSwapsToSort(vector<int>& arr, int n) {
    vector<bool> visited(n + 1, false);
    int swaps = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        int cycleSize = 0;
        int j = i;

        // index i -> value a[i] should be at position a[i]
        while (!visited[j]) {
            visited[j] = true;
            j = arr[j];  
            cycleSize++;
        }

        swaps += cycleSize - 1;
    }
    return swaps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);  // 1-indexed so n tak chhaie index
    for (int i = 1; i <= n; i++) cin >> arr[i];

    cout << minSwapsToSort(arr, n) << "\n";
    return 0;
}


//tarika 2
//ans= n-no of cycles

// 0 index
#include <bits/stdc++.h>
using namespace std;

int countCycles0Indexed(vector<int>& arr, int n) {
    vector<bool> visited(n, false);
    int cycles = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

            cycles++;   // start of a new cycle
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j] - 1;  
            }
        
    }
    return cycles;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int cycles = countCycles0Indexed(arr, n);
    cout << "Number of cycles: " << cycles << "\n";
    cout << "Minimum swaps: " << (n - cycles) << "\n";
}


// 1 index

#include <bits/stdc++.h>
using namespace std;

int countCycles1Indexed(vector<int>& arr, int n) {
    vector<bool> visited(n + 1, false);
    int cycles = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

            cycles++;   // start of a new cycle
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j];  
            }
        
    }
    return cycles;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1); // 1-indexed toh n index tak chahie
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int cycles = countCycles1Indexed(arr, n);
    cout << "Number of cycles: " << cycles << "\n";
    cout << "Minimum swaps: " << (n - cycles) << "\n";
}


// m2 dsu


// tarika 1

//ans= sum of all (cycle length - 1)



// 0 based indexing


#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    public:
    vector<int>  parent, size;
    DisjointSet(int n) {
        
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n); // 0-indexed
    for (int i = 0; i < n; i++) cin >> arr[i];

    DisjointSet ds(n);
    for(int i=0;i<n;i++){
         ds.unionBySize(arr[i],i+1);
    }
    int swaps=0;
    for(int i=1;i<=n;i++){
        if(ds.findUPar(i)==i) swaps+=(ds.size[i]-1);
    }

    cout<<swaps<<endl;
    
    return 0;
}

// 1 indexed 
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int>  parent, size;
    DisjointSet(int n) {
        
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1); // 1-indexed
    for (int i = 1; i <=n; i++) cin >> arr[i];

    DisjointSet ds(n);
    for(int i=1;i<=n;i++){
         ds.unionBySize(arr[i],i);
    }
    int swaps=0;
    for(int i=1;i<=n;i++){
        if(ds.findUPar(i)==i) swaps+=(ds.size[i]-1);
    }

    cout<<swaps<<endl;
    
    return 0;
}


//tarika 2
//ans=n-no of cycles

// 0 indexed

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int>  parent, size;
    public:
    DisjointSet(int n) {
        
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n); // 0-indexed
    for (int i = 0; i < n; i++) cin >> arr[i];

    DisjointSet ds(n);
    for(int i=0;i<n;i++){
        ds.unionBySize(arr[i],i+1);
    }
    int cycles=0;
    for(int i=1;i<=n;i++){
        if(ds.findUPar(i)==i) cycles++;
    }

    cout<<n-cycles<<endl;
    
    return 0;
}

// 1 indexed


#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int>  parent, size;
    public:
    DisjointSet(int n) {
        
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1); // 1-indexed
    for (int i = 1; i <=n; i++) cin >> arr[i];

    DisjointSet ds(n);
    for(int i=1;i<=n;i++){
         ds.unionBySize(arr[i],i);
    }
    int cycles=0;
    for(int i=1;i<=n;i++){
        if(ds.findUPar(i)==i) cycles++;
    }

    cout<<n-cycles<<endl;
    
    return 0;
}
