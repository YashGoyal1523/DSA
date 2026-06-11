//lc 3588

 //use dfs/bfs to find max depth
 //odd 1 + remaining 2
 //2^(maxDepth-1)
class Solution {
public:
    
     int MOD = 1e9 + 7;

    int pow2(int x){
        int ans=1;
        for(int i=1;i<=x;i++){
            ans=(ans*2)%MOD;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        int n=edges.size()+1;
        
        
        //bfs
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q;
        q.push({1, 0});

        vector<int> vis(n + 1, 0);
        vis[1] = 1;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, depth + 1});
                }
            }
        }
        
       
        int ways=pow2(maxDepth-1);
        return ways;
    }
};