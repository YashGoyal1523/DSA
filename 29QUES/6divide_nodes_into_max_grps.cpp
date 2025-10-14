// lc 2493

// check if graph is bipartite
// no -> not possible return -1
// yes->possible ...find further
// to get ans har component ka max no of group ko add krdo 
// ek component ka max nikane k lye... uske har node se max no of grp mein se max lelo
// node se max grp nikalne ke liye node se levels count krne h ....bfs/dfs chalake levels ginlo ..bfs is preffered


class Solution {
public:

    bool dfs(int node,int col,vector<int>&color,vector<vector<int>>& graph){
        color[node]=col; // node ko color krdo
        // nbrs pe jao
        for(auto i : graph[node]){
            if(color[i]==-1){ // if not colored 
               bool ans= dfs(i,!col,color,graph); // opposite color hoga....
               if(ans==false) return false;
            }
            else{ //if colored 
                if(color[i]==col) //if same colored to node
                return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1); // will maintain color of nodes //0 for color 1 , 1 for color 2 , -1 for not colored  // work of visited array will be done by this only so no need for external visited array...if not colored then not visited

        //disconnected component ho skte isilye sabse chalayege
        for(int i=0;i<n;i++){
            if(color[i]==-1) // if not colored (not visited)
            {
                bool ans=dfs(i,0,color,graph);  // kisi bhi color se shuru krlo ...0 se krlia
                if(ans==false) return false;
            }
        }
        return true;
    }

    int bfs(vector<vector<int>>&adj,int n,int node){
        queue<int>q;
        vector<int>vis(n,0);
        q.push(node);
        vis[node]=1;

        int level=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){ //iss level ke saare nodes queue m h // level wise krne k liye
            int currnode=q.front();
            q.pop();
            for(auto nbr:adj[currnode]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
            }
            level++;
        }
        //ek extra level add hojayega

        return level-1;

    }

    void dfs(int node, vector<int>levels,vector<vector<int>>&adj,int &compMax,  vector<int>&vis){
        compMax=max(compMax,levels[node]);
        vis[node]=1;

        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr,levels,adj,compMax,vis);
            }
        }


    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i:edges){
            int u=i[0]-1; // convrting to 0 based indexing
            int v=i[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // bipartite check
        if(!isBipartite(adj)) return -1;

        // levels for each node using bfs
        vector<int>levels(n,0);
        for(int node=0;node<n;node++){
            levels[node]=bfs(adj,n,node);
        }
        //har component ka max leke add krlete
        int ans=0;
        vector<int>vis(n,0);
        for(int node=0;node<n;node++){
            if(!vis[node]){
            int compMax=0;
            dfs(node,levels,adj,compMax,vis);
            ans+=compMax;
            }
        }

        return ans;

    }
};