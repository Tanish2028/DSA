class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        
        int peak = 0;
        int valley = 0;

        int n = nums.size();

        for(int i = 1;i<n-1;i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                peak += nums[i];
            }
            if(nums[i] < nums[i-1] && nums[i] < nums[i+1]){
                valley += nums[i];
            }
        }

        return peak - valley;
    }
};