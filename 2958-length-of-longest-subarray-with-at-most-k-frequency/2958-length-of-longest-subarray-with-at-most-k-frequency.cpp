class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int,int>mpp; //nums[i] -> freq

        int l = 0;
        int r = 0;
        int len = 0;
        int maxi = INT_MIN;

        while(r<n){
            
            mpp[nums[r]]++;
            
            if(mpp[nums[r]] <= k){
                len = r - l + 1;
                maxi = max(maxi,len);
            }
            else{
                while(mpp[nums[r]] > k){
                    mpp[nums[l]]--;
                    l++;
                }
            } 
            r++;
        }

        return maxi;
    }
};