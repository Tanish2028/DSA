class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0] < b[0];
        });


        vector<vector<int>> ans;

        ans.push_back({intervals[0][0],intervals[0][1]});

        for(auto it:intervals){
            if(it[1] >= ans.back()[1] && it[0] <= ans.back()[1]){
                ans.back()[1] = it[1];
            }
            else if(it[1] <= ans.back()[1] && it[0] <= ans.back()[1]){}
            else{
                ans.push_back({it[0],it[1]});
            }
        }

        return ans;
    }
};