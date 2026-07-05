class Solution {
public:
    int mod = 1e9 + 7;

    int getMaxSum(int i,int j,int n,int m,vector<string>& board,vector<vector<int>>& dp){

        if(i < 0 || j < 0) return -1e9;

        if(board[i][j] == 'X') return -1e9;

        if(i == 0 && j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int up = 0;
        int upLeft = 0;
        int left = 0;
        if( i == n-1 && j == m-1){
            up = 0 + getMaxSum(i-1,j,n,m,board,dp);
            upLeft = 0 + getMaxSum(i-1,j-1,n,m,board,dp);
            left = 0 + getMaxSum(i,j-1,n,m,board,dp);
        }
        else{
            int num = board[i][j] - '0';
            up = num + getMaxSum(i-1,j,n,m,board,dp);
            upLeft = num + getMaxSum(i-1,j-1,n,m,board,dp);
            left = num + getMaxSum(i,j-1,n,m,board,dp);
        }
        

        return dp[i][j] = max(up,max(upLeft,left));
    }

    int getCount(int i,int j,int n,int m,vector<string>& board,int maxSum,vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0) return 0;

        if(board[i][j] == 'X') return 0;

        if(i == 0 && j == 0){
            if(maxSum == 0) return 1;
            return 0;
        }
        if(dp[i][j][maxSum] != -1) return dp[i][j][maxSum];
        int up = 0;
        int upLeft = 0;
        int left = 0;
        if( i == n-1 && j == m-1){
            up = 0 + getCount(i-1,j,n,m,board,maxSum,dp);
            upLeft = 0 + getCount(i-1,j-1,n,m,board,maxSum,dp);
            left = 0 + getCount(i,j-1,n,m,board,maxSum,dp);
        }
        else{
            int num = board[i][j] - '0';
            up = getCount(i-1,j,n,m,board,maxSum - num,dp);
            upLeft = getCount(i-1,j-1,n,m,board,maxSum - num,dp);
            left = getCount(i,j-1,n,m,board,maxSum - num,dp);
        }
        

        return dp[i][j][maxSum] = (up + upLeft + left) %mod;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        

        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> dp1(n,vector<int>(m,-1));
        int maxSum = getMaxSum(n-1,m-1,n,m,board,dp1) % mod;

        if(maxSum < 0){
            return {0,0}; 
        }
        
        vector<vector<vector<int>>> dp2(n,vector<vector<int>>(m,vector<int>(maxSum + 1,-1)));
        int Count = getCount(n-1,m-1,n,m,board,maxSum,dp2);
        vector<int>ans;
        ans.push_back(maxSum);
        ans.push_back(Count);

        return ans;
    }
};