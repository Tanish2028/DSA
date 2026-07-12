class Solution {
public:
    int mod = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        
        int n = nums.size();

        
        long long availableResource = k;
        int cost = 0;
        
        long long idx = 0;
        for(int i = 0;i<n;i++){

            if(nums[i] <= availableResource){
                cost += 0;
                availableResource -= nums[i];
            }

            else{
                
                long long count = 0;
                long long diff = nums[i] - availableResource;

                long long iter = (diff+k-1)/k;

                availableResource += (iter*k);
                count = ((2LL*(idx+1) + (iter-1))%mod)*iter/2;

                cost = (cost %mod +  count) %mod;
                idx += iter;
                availableResource -= nums[i];
            }
        }

        return cost %mod;
    }
};