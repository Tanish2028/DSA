class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& temp,vector<int>& vis,int n,int node){

     if(node == n-1){
        ans.push_back(temp);
        return;
     }

     for(auto it:graph[node]){
        if(!vis[it]){
            temp.push_back(it);
            vis[it] = 1;
            dfs(graph,ans,temp,vis,n,it);
            vis[it] = 0;
            temp.pop_back();
        }
     }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<vector<int>>ans;

        vector<int>temp;
        vector<int>vis(n,0);
        vis[0] = 1;
        temp.push_back(0);
        dfs(graph,ans,temp,vis,n,0);

        return ans;
    }
};