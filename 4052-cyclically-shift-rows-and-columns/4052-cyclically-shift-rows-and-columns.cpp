class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        
        for(int i = 0;i<n;i++){
            int rot = rowShift[i] % n;

            reverse(grid[i].begin(),grid[i].begin()+rot);
            reverse(grid[i].begin()+rot,grid[i].end());
            reverse(grid[i].begin(),grid[i].end());
        }

        for(int j = 0;j<n;j++){
            int rot = colShift[j] % n;

            for(int i = 0;i<rot;i++){
                int temp = grid[0][j];

                for(int k = 0;k<n-1;k++){
                    grid[k][j] = grid[k+1][j];
                }

                grid[n-1][j] = temp;
            }
        }


        return grid;
    }
};