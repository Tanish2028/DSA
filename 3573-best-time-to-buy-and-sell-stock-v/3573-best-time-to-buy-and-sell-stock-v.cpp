class Solution {
public:
    long long func(int idx,vector<int>& prices,int k,int n,int cases,vector<vector<vector<long long>>>& dp){
        if(idx >= n){

            if(cases == 0){
                return 0;
            }
            return INT_MIN;
        }

        if(dp[idx][k][cases] != LLONG_MIN){
            return dp[idx][k][cases];
        }

        long long skip = func(idx+1,prices,k,n,cases,dp);

        long long take = INT_MIN;
        
        if(k>0){

            if(cases == 1){ //sell
                take = prices[idx] + func(idx+1,prices,k-1,n,0,dp);
            }
            else if(cases == 2){ //buy
                take = -prices[idx] + func(idx+1,prices,k-1,n,0,dp);
            }
            else{
                take = max(-prices[idx] + func(idx+1,prices,k,n,1,dp), prices[idx] + func(idx+1,prices,k,n,2,dp)); 
            }
        }

        return dp[idx][k][cases] = max(take,skip);

 
    }
    long long maximumProfit(vector<int>& prices, int k) {
        
        int n = prices.size();
        
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(k+1,vector<long long>(3,LLONG_MIN)));

        return func(0,prices,k,n,0,dp);
    }
};