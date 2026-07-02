class Solution {
public:
    
    // bool func(int i,int j,int m,int n,vector<vector<int>>& grid,int val,vector<vector<int>>& vis){
    //     if(i < 0 || i >= m || j < 0 || j >= n) return false;
        
    //     if(vis[i][j]) return false;

    //     val -= grid[i][j];
    //     if(val <= 0) return false;

    //     if(i == m-1 && j == n-1){
    //         return true;
    //     }
        
    //     vis[i][j] = true;

    //     bool ans = func(i-1,j,m,n,grid,val,vis) || func(i+1,j,m,n,grid,val,vis) || func(i,j-1,m,n,grid,val,vis) || func(i,j+1,m,n,grid,val,vis);

    //     vis[i][j] = false;

    //     return ans; 
        
    // }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>> pq;
        
        vector<int>delrow{-1,0,1,0};
        vector<int>delcol{0,1,0,-1};
        pq.push({health,{0,0}});
        
        vector<vector<int>> vis(m,vector<int>(n,0));

        while(!pq.empty()){

            int val = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(vis[row][col]) continue;
            vis[row][col] = 1;

            val -= grid[row][col];
            if(row == m-1 && col == n-1) {
                if(val > 0) return true;
                return false;
            }

            for(int i = 0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]){

                    pq.push({val,{nrow,ncol}});
                }
            }

        }

        return false;


    }
};














