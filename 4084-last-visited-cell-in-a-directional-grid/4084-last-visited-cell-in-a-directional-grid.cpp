class Solution {
public:
    
    vector<int> func(int i,int j,vector<vector<char>>& grid,vector<vector<int>> &vis,int m,int n,int prevR,int prevC){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return {prevR,prevC};
        }

        if(vis[i][j]){
            return {prevR,prevC};
        }
        vis[i][j] = 1;
        char ch = grid[i][j];

        if(ch == 'R'){
            return func(i,j+1,grid,vis,m,n,i,j);
        }
        else if(ch == 'L'){
            return func(i,j-1,grid,vis,m,n,i,j);
        }
        else if(ch == 'U'){
            return func(i-1,j,grid,vis,m,n,i,j);
        }
       
        return func(i+1,j,grid,vis,m,n,i,j);
    
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

       
        vis[0][0] = 1;
        char ch = grid[0][0];
        //L => i,j-1
        //R => i,j+1
        //U => i-1,j
        //D => i+1,j
        
        if(ch == 'R'){
            return func(0,1,grid,vis,m,n,0,0);
        }
        else if(ch == 'L'){
            return func(0,-1,grid,vis,m,n,0,0);
        }
        else if(ch == 'U'){
            return func(-1,0,grid,vis,m,n,0,0);
        }
       
        return func(1,0,grid,vis,m,n,0,0);
        
    }
};