class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int n = nums.size();

        long long count = 0;
        long long len = 0;

        int l = 0;
        int r = 0;

        while(r<n){
            if(nums[r] >= minK && nums[r] <= maxK){
                len++;
                count += len;
            }
            else{
                len = 0;
            }
            r++;
        }
        return count;
    }
};