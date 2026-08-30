class Solution {
public:
    
    int func(int idx,int prev,int n,string& s,vector<vector<int>>& dp){

        if(idx >= n){
            return 0;
        }

        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }

        int flip = INT_MAX;
        int notflip = INT_MAX;


        if(s[idx] == '0'){
            if(prev == 0){
                flip = 1 + func(idx+1,1,n,s,dp);
                notflip = 0 + func(idx+1,0,n,s,dp);
            }
            else{
                flip = 1 + func(idx+1,1,n,s,dp);
            }
        }

        else{
            if(prev == 0){
                flip = 1 + func(idx+1,0,n,s,dp);
                notflip = 0 + func(idx+1,1,n,s,dp);
            }
            else{
                notflip = 0 + func(idx+1,1,n,s,dp);
            }
        }

        return dp[idx][prev] = min(flip,notflip);



    }
    int minFlipsMonoIncr(string s) {

        int n = s.length();

        vector<vector<int>>dp(n,vector<int>(2,-1));

        return func(0,0,n,s,dp);

        
    }
};