class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis,int& nodes,int& edges,int count,vector<int>& storeComp){

        vis[node] = 1;
        nodes++;
        edges += adj[node].size();
        storeComp[node] = count;

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,nodes,edges,count,storeComp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        int count = 0;
        
        vector<int> storeComp(n,-1);
  
        int ans = 0;

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int nodes = 0;
                int edges = 0;
                dfs(i,adj,vis,nodes,edges,count,storeComp);

                edges = edges/2;

                if(((nodes*(nodes-1))/2) == edges){
                    ans++;
                }
                count++;
            }
            
          
        }

        return ans;
    }
};