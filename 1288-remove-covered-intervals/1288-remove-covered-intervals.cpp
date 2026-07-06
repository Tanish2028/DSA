class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){

            return a[0] < b[0];
        });

        vector<pair<int,int>> vec;

        vec.push_back({intervals[0][0],intervals[0][1]});

        for(auto it:intervals){
            if(it[1] <= vec.back().second){}
            else if(it[0] == vec.back().first){
                vec.pop_back();
                vec.push_back({it[0],it[1]});
            }
            else{
                vec.push_back({it[0],it[1]});
            }
        }

        int count = vec.size();

        return count;
    }
};