class Solution {
public:
    
    bool canReach(vector<int>& start, vector<int>& target) {
        
        int stX = start[0];
        int stY = start[1];
        int endX = target[0];
        int endY = target[1];

        queue<pair<pair<int,int>,int>>q;
        q.push({{stX,stY},0});
        
        vector<int>delrow{-2,-1,1,2,2,1,-1,-2};
        vector<int>delcol{1,2,2,1,-1,-2,-2,-1};
        
        vector<vector<int>>vis(8,vector<int>(8,0));

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int move = q.front().second;
            q.pop();

            if(x == endX && y == endY && move%2 == 0){
                return true;
            }

            for(int i = 0;i<8;i++){
                int nrow = x + delrow[i];
                int ncol = y + delcol[i];

                if(nrow>=0 && nrow<8 && ncol>=0 && ncol<8 && !vis[nrow][ncol]){
                  
                    q.push({{nrow,ncol},move+1});
                    vis[nrow][ncol] = 1;
                }
            }

        }

        return false;
    }
};