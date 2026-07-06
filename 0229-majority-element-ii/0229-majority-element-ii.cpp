class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int>mpp;

        int n = nums.size();
        vector<int>ans;

        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto m:mpp){
            if(m.second > n/3) ans.push_back(m.first);
        }

        return ans;
    }
};