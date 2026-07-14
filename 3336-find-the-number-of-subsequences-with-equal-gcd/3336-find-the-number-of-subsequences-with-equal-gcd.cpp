class Solution {
public:
    int mod = 1e9 + 7;
    int func(int i,int n,vector<int>& nums,int prevGCDSeq1,int prevGCDSeq2,vector<vector<vector<int>>>& dp){
        
        if(i >= n){
            if(prevGCDSeq1 != 0 && prevGCDSeq2 != 0){
                return prevGCDSeq1 == prevGCDSeq2;
            }

            return 0;
        }
        if(dp[i][prevGCDSeq1][prevGCDSeq2] != -1) {
            return dp[i][prevGCDSeq1][prevGCDSeq2];
        }

        long long take1 = 0;
        long long take2 = 0;
        long long skip = 0;

        //take seq1 and not take seq2
        if(prevGCDSeq1 == 0){
            take1 = func(i+1,n,nums,nums[i],prevGCDSeq2,dp);
        }
        else{
            take1 = func(i+1,n,nums,gcd(prevGCDSeq1,nums[i]),prevGCDSeq2,dp);
        }

        //not take seq1 and take seq2
        if(prevGCDSeq2 == 0){
            take2 = func(i+1,n,nums,prevGCDSeq1,nums[i],dp);
        }
        else{
            take2 = func(i+1,n,nums,prevGCDSeq1,gcd(prevGCDSeq2,nums[i]),dp);
        }

        //not take seq1 and not take seq2
        skip = func(i+1,n,nums,prevGCDSeq1,prevGCDSeq2,dp);

        return dp[i][prevGCDSeq1][prevGCDSeq2] = (take1 + take2 + skip)%mod;

    }
    int subsequencePairCount(vector<int>& nums) {
        
        int n = nums.size();
        
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(201,vector<int>(201,-1)));
        return func(0,n,nums,0,0,dp);
        
    }
};