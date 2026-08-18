class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(k == n){
            sort(nums.begin(),nums.end());
            return nums[n-1];
        }

        unordered_map<int,int>mpp;

        if(k == 1){
            for(int i = 0;i<n;i++){
                mpp[nums[i]]++;
            }
            
            int maxi = -1;

            for(auto mp:mpp){
                if(mp.second == 1){
                    maxi = max(maxi,mp.first);
                }
            }

            return maxi;
        }

        

        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }

        if(mpp[nums[0]] == 1 && mpp[nums[n-1]] == 1){
            return max(nums[0],nums[n-1]);
        }
        else if(mpp[nums[0]] == 1 && mpp[nums[n-1]] != 1){
            return nums[0];
        }
        else if(mpp[nums[0]] != 1 && mpp[nums[n-1]] == 1){
            return nums[n-1];
        }
        return -1;
    }
};