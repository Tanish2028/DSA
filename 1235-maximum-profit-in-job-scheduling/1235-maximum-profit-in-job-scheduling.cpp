// class Solution {
// public:
//     int func(vector<int>& startTime, vector<int>& endTime, vector<int>& profit,int idx,int st,int n){
        // if(idx == n){
        //     return 0;
        // }

        // int maxi = 0;

        // for(int i = idx;i<n;i++){
        //     int st1 = startTime[i];
        //     int ed1 = endTime[i];

        //     if(st1 < st){
        //         continue;
        //     }

        //     else{
        //         int pro = profit[i] + func(startTime,endTime,profit,i+1,ed1,n);
        //         maxi = max(maxi,pro);
        //     }
        // }

        // return maxi;

class Solution {
public:
    int func(vector<pair<int,pair<int,int>>>& vec,int idx,int n,vector<int>& dp){
         if(idx == n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int skip = func(vec,idx+1,n,dp);

        int take = 0;

        int next = lower_bound(
            vec.begin() + idx + 1,
            vec.end(),
            vec[idx].second.first,
            [](const pair<int, pair<int, int>>& job, int time) {
                return job.first < time;
            }
        ) - vec.begin();

        
        take = vec[idx].second.second + func(vec,next,n,dp);
        

        return dp[idx] = max(skip,take);


    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        
        vector<pair<int,pair<int,int>>>vec;

        for(int i = 0;i<n;i++){
            vec.push_back({startTime[i],{endTime[i],profit[i]}});
        }

        sort(vec.begin(),vec.end());

        vector<int>dp(n,-1);

        return func(vec,0,n,dp);
    }
};