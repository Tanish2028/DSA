class Solution {
public:
    vector<int>delrow{-1,0,1,0};
    vector<int>delcol{0,1,0,-1};

    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& vis){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }

        vis[i][j] = 1;

        for(int idx = 0;idx<4;idx++){
            int nrow = i + delrow[idx];
            int ncol = j + delcol[idx];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !grid[nrow][ncol] && !vis[nrow][ncol]){
                dfs(nrow,ncol,m,n,grid,vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i = 0;i<m;i++){
            if(grid[i][0] == 0){
                dfs(i,0,m,n,grid,vis);
            }
        }
        for(int i = 0;i<n;i++){
            if(grid[0][i] == 0){
                dfs(0,i,m,n,grid,vis);
            }
        }
        for(int i = 0;i<m;i++){
            if(grid[i][n-1] == 0){
                dfs(i,n-1,m,n,grid,vis);
            }
        }
        for(int i = 0;i<n;i++){
            if(grid[m-1][i] == 0){
                dfs(m-1,i,m,n,grid,vis);
            }
        }

        int count = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                
                if(grid[i][j] == 0 && !vis[i][j]){
                    dfs(i,j,m,n,grid,vis);
                    count++;
                    }
        }
    }

    return count;

    }
};