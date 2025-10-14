// level track rkhna in graph bfs

//counting levels from a srcnode
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
