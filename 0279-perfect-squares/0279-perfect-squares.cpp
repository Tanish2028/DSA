class Solution {
public:

    int func(int n,vector<int>& dp){

        if(n == 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int count = INT_MAX;
     

        for(int i = 1;i*i<=n;i++){
        

            int count1 = 1 + func(n - i*i,dp);

            count = min(count,count1);
        }

        return dp[n] = count;
    }
    int numSquares(int n) {
        
        vector<int>dp(n+1,-1);

        return func(n,dp);
    }
};