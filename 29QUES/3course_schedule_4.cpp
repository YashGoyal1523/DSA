//lc 1462

//https://youtu.be/ScJNPlYz1J4?si=IYcQTbGsJLiKwEoD

// consider courses as graph nodes
// edge : u->v  if u is prerequisite for v
// note u->v->z : u is prerequsite for z
 
// m1 
// simple traversal
// for each query... prerequisite node (src node) se traversal krke check krege ki destination node (target node) reach hogaa ya nhi..if hogi then yes else no

//dfs for traversal

class Solution {
public:
bool dfs(vector<vector<int>>&adj,int src,int target,vector<int>&vis){

    if(src==target) return true;

    vis[src]=1;


    for(auto nbr:adj[src]){
        if(!vis[nbr]){
           bool isReachable=dfs(adj,nbr,target,vis);
            if(isReachable) return true;
        }

    }

return false;

}
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int src=queries[i][0];
            int target=queries[i][1];
             vector<int>vis(n,0);
            bool a=dfs(adj,src,target,vis);
            ans.push_back(a);
        }
        return ans;
    }
};

// m2
// similar to method 1
// precomputing prerequisites 
// har node se har node ka check krlege ki phle wala dusre ka prerequisite h ya ni
// iske liye phle wale se simple traversal krke check krlege ki dusra reach hora ya ni..is yes then hai else no
// har query mein fir seedha check krlege ki prerequisite h ya ni

class Solution {
public:
bool dfs(vector<vector<int>>&adj,int src,int target,vector<int>&vis){

    if(src==target) return true;

    vis[src]=1;


    for(auto nbr:adj[src]){
        if(!vis[nbr]){
           bool isReachable=dfs(adj,nbr,target,vis);
            if(isReachable) return true;
        }

    }

return false;
}

void precompute( vector<vector<int>>adj, vector<vector<bool>>&prereq,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                vector<int>vis(n,0);
                if(dfs(adj,i,j,vis)) prereq[i][j]=true;
            }
        }
    }
}



    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }

        vector<vector<bool>>prereq(n,vector<bool>(n,false)); // (i,j) will store whether i is a prerequisite for j or not
        precompute(adj,prereq,n);

    int q=queries.size();
        vector<bool>ans;
        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            ans.push_back(prereq[u][v]);
        }
        return ans;
    }
};

// m3
// toposort
// kahns algo
//We need to find a way to process nodes in the correct order, ensuring that each node is processed only after its dependencies are handled. This is where topological sorting comes into play. Kahn’s algorithm is a great fit for this task because it respects the dependencies of each node, ensuring nodes are only visited once their prerequisites are completed.
// topo order nikalte hue elements ke prerequisites maintain krte chlo .... ( prereq nodes of a nbr node = curr node + prereq of curr node )
// fir har query mein seedha check krlo


class Solution {
public:


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        //kahn s algo
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto i:prerequisites){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        unordered_map<int,unordered_set<int>>prereq; // will maintain prerequisites of nodes

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
                //nbr ke prereq m daalo node ko
                prereq[nbr].insert(node);
                // node ke prereq is also prereq of nbr....voh bhi daalo
                for(auto p:prereq[node]){
                    prereq[nbr].insert(p);
                }

            }
        }

        // process queries
        vector<bool>ans;
        for(auto i:queries){
            int u=i[0];
            int v=i[1];
            bool isprereq=prereq[v].contains(u);
            ans.push_back(isprereq);
        }
        
  return ans;
    }
};