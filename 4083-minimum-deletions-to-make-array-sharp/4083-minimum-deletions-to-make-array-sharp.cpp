class Solution {
public:
    int minDeletions(vector<int>& nums) {
        
        int count = 0;

        int last = nums[0];
        int n = nums.size();

        for(int i = 1;i<n;i++){
            if(nums[i] == last){
                count++;
                
            }
            last = nums[i];
        }

        return count; 
    }
};