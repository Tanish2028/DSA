class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        vector<int>delrow{-1,0,1,0};;
        vector<int>delcol{0,1,0,-1};

        int m = maze.size();
        int n = maze[0].size();

        int entX = entrance[0];
        int entY = entrance[1];

        queue<pair<pair<int,int>,int>>q; // {{row,col},steps};

        vector<vector<int>> vis(m,vector<int>(n,0));
        
        q.push({{entX,entY},0});

        while(!q.empty()){
            auto elem = q.front();
            q.pop();

            int x = elem.first.first;
            int y = elem.first.second;
            int steps = elem.second;
            
            if(x == entX && y == entY){
                //it is not valid exit point
            }

            else{
                if(x == 0 || x == m-1 || y == 0 || y == n-1){
                    return steps;
                }
            }

            for(int i = 0;i<4;i++){
                int nrow = x + delrow[i];
                int ncol = y + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && maze[nrow][ncol] == '.'){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }

        return -1;
    }
};