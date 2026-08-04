class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int mini = nums[0];
        int maxi = nums[nums.size()-1];

        map<int,int>mpp;

        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<int>ans;
        for(int i = mini;i<=maxi;i++){
            if(mpp[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};