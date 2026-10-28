class Solution {
public:
    void func(int i,int j,vector<vector<int>>& grid,int n,int m,vector<vector<unordered_set<int>>>& dp){

        if(i == 0 && j == 0){
            dp[i][j].insert(grid[i][j]);
            return;
        }
        if(j>=m || i>=n){
            return ;
        } 

        if(i > 0){
            for(auto val : dp[i-1][j]){
                dp[i][j].insert(val ^ grid[i][j]);
            }
        }
        
        if(j > 0){
            for(auto val : dp[i][j-1]){
                dp[i][j].insert(val ^ grid[i][j]);
            }
        }
    }
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                func(i,j,grid,n,m,dp);
            }
        }

        int ans = INT_MAX;
        for(auto val:dp[n-1][m-1]){
            ans = min(ans,val);
        }
        if(ans == INT_MAX){
            return -1;
        }

        return ans;
        
    }
};