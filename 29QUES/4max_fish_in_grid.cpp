//lc 2658

// consider water cells as graph nodes
// disconnected components ho skte

// m1- bfs/dfs
// har component m bfs ya dfs se ginlo fish and sabka max lelo
// -> iske liye vhi hojayega...disconnected graph m bfs/dfs wala tarika...ie..saare water cells ko ek ek baari src node leke ...unvisited walo mein chalado ......and ginlo

//bfs
class Solution {
public:

int bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int srcx,int srcy){
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>>q;
    q.push({srcx,srcy});
    vis[srcx][srcy]=1;

    int count=0;

    while(!q.empty()){
        auto node=q.front();
        int currx=node.first;
        int curry=node.second;
        count+=grid[currx][curry];
        cout<<count;
        q.pop();

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newx=currx+dx[i];
            int newy=curry+dy[i];

            if(newx>=0&&newx<m&&newy>=0&&newy<n&&!vis[newx][newy]&&grid[newx][newy]>0){
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
    }
    return count;
}



    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<pair<int,int>>src;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0) src.push_back({i,j});
            }
        }
        cout<<src.size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<src.size();i++){
            int srcx=src[i].first;
            int srcy=src[i].second;
            if(!vis[srcx][srcy]){
            int currans=bfs(grid,vis,srcx,srcy);
            ans=max(ans,currans);
            }
        }

        return ans;
    }
};

// m2 dsu
//https://youtu.be/kfs9vzv7kHc?si=6YwK_0in2JH9iMY9

  class DisjointSet{  
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i]=0;
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

    void setSize(int fishcnt,int nodeidx){   
                size[nodeidx]=fishcnt;
  
    }

    int maxfishcnt(){
        return *max_element(size.begin(),size.end());
    }
};


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DisjointSet ds(n*m);
        
        // intialising size array with initial fish count
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    int nodeidx=i*n+j;
                    ds.setSize(grid[i][j],nodeidx);
                }
            }
        }

                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
         for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]>0){
                 for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy=y+dy[i];

                    if(newx>=0&&newy>=0&&newx<m&&newy<n&&grid[newx][newy]>0){
                        int nodeidx=x*n+y;
                        int adjnodeidx=newx*n+newy;
                        ds.unionBySize(nodeidx,adjnodeidx);
                    }
                 }
                    
                }
            }
        }

        int ans=ds.maxfishcnt();

        return ans;


    }
};