// level track rkhna in graph bfs

//counting levels from a srcnode
int bfs(vector<vector<int>>&adj,int n,int node){
        queue<int>q;
        vector<int>vis(n,0);
        q.push(node);
        vis[node]=1;

        int level=0;
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
      
        return level;

    }


 // we can use checkmark approach also that we did in level order traversal of binary tree
 // similalry in level order traversal of binary tree we can use this queue size approach also 
