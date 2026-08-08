class Solution {
public:
    
    int dfs(int node,vector<vector<int>>& adj,int parent,vector<bool>& hasApple,int n){
        
        int cost = 0;

        for(auto it:adj[node]){
            
            if(it == parent){
                continue;
            }

            int childTree = dfs(it,adj,node,hasApple,n);

            if(childTree > 0 || hasApple[it]){
                cost += childTree + 2;
            }
        }

        return cost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>>adj(n);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        return dfs(0,adj,-1,hasApple,n);

    }
};