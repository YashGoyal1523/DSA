//lc 684

// https://youtu.be/EawxDEOxeIk?si=iiSL2lrhO-hyfZ0s

//method 1 : traversal
// 1 edge extra
// edges pe traverse krte jao.....if both nodes are already present in graph and connected via some path(bfs/dfs se hojayega) then ans milgya rukjao else edge lagado dono mein and aage bhado

class Solution {
public:

bool dfs(int src,int target,vector<int>&vis,vector<vector<int>>&adj){
    if(src==target) return true;

    vis[src]=1;

    for(auto nbr:adj[src]){
        if(!vis[nbr]){
            bool ans=dfs(nbr,target,vis,adj);
            if(ans) return true;
        }
    }

    return false;
}


    bool connected(int u,int v,vector<vector<int>>&adj,int n){
        vector<int>vis(n+1,0);
        // checking whether they are connected by dfs from u to v
        bool ans=dfs(u,v,vis,adj);

        return ans;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size(); // no of nodes // atleast n-1 edges requred for n nodes to be connected ....1 extra edge...therefore no of edges given is n
        vector<vector<int>>adj(n+1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(adj[u].size()!=0&&adj[v].size()!=0&&connected(u,v,adj,n)){ //both present and connected
               ans=edges[i];
               }
            
                adj[u].push_back(v);
                adj[v].push_back(u);
               

        }
    return ans;
    }
};


// method 2 - dsu

// edges pe traverse  kro ...dono nodes ka  uPar same hua toh yhi ans h rukjao else union krdo aage bhado

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // path compression krli
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else { //==
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size(); // no of nodes
        DisjointSet ds(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                ans=edges[i];
                break;
            }
            ds.unionByRank(u,v);

        }

        return ans;
    }
};