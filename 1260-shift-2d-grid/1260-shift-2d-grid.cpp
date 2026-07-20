class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        
        while(k>0){
            vector<vector<int>> mat(m,vector<int>(n));
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(j+1 < n){
                        mat[i][j+1] = grid[i][j];
                    }
                    if(i+1 < m){
                        mat[i+1][0] = grid[i][n-1];
                    }
                    mat[0][0] = grid[m-1][n-1];
                }
            }
            grid = mat;
            k--;
    }
    return grid;
    }
};