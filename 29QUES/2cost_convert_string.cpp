// lc 2976


// // note  ek se dusre mein multiple cost ho skte

// // will use floyd warshall


// class Solution {
// public:
//     void makegraph(unordered_map<int, list<pair<int, int>>>& adj, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         for (int i = 0; i < original.size(); i++) {  // directed graph banega
//             adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
//         }
//     }

//     void floydwarshall(vector<vector<int>>& costm, unordered_map<int, list<pair<int, int>>>& adjList, int n) {
//      // cost matrix toh bani hui h

//         // Initial states: 
//         // self to self weight is zero
//         for (int i = 0; i < n; i++) {
//             costm[i][i] = 0;
//         }
//         // graph m diye hue weights daal lete
//         for (auto a : adjList) {
//             int u = a.first;
//             for (auto b : a.second) {
//                 int v = b.first;
//                 int wt = b.second;
//                 costm[u][v] = min(costm[u][v], wt); //  ek node se dusre mein multiple weights ho skte ...and hume min wala weight lena....isiliye yeh min wala system kiya
//             }
//         }

//         // main logic
//         for (int helper = 0; helper < n; helper++) {
//             for (int src = 0; src < n; src++) {
//                 for (int dest = 0; dest < n; dest++) {
//                     costm[src][dest] = min(costm[src][dest], costm[src][helper] + costm[helper][dest]);
//                 }
//             }
//         }
//         // ab costm mein min costs stored hoge ...note jisme 1e9 hoga uska mtlb h voh character conversion not possible
//     }

//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         // phle graph banalete
//         unordered_map<int, list<pair<int, int>>> adj;
//         makegraph(adj, original, changed, cost);

//     // ab har se har ka min cost nikal lete 
//         int n = 26; // given lower case characters only .....so 26 characters possible
//         vector<vector<int>> costm(n, vector<int>(n, 1e9));  //cost matrix.... isme store krege costs
//         floydwarshall(costm, adj, n);

//     // ab ans nikall lete
//         long long ans = 0;
//         for (int i = 0; i < source.size(); i++) {
//             if (source[i] != target[i]) {
//                 int conversionCost = costm[source[i] - 'a'][target[i] - 'a'];
//                 if (conversionCost == 1e9) return -1;  // character conversion not possible ....so source to target nhi ho payega 
//                 ans += conversionCost;
//             }
//         }
//         return ans;
//     }
// };


// yeh adj list banaye bina bhi kr skte jse yeh threshold (lc 1334) wale ques m kiya h...