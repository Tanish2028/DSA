class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
     
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxVal = nums[n-1] + k;

        map<int,int>diff;
        unordered_map<int,int>freq;
        

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            int l = max(nums[i] - k , 0);
            int r = min(nums[i] + k,maxVal);

            diff[l]++;
            diff[r+1]--;
            diff[nums[i]] += 0;
        }
        
        int result = 1;
        
        int cumSum = 0;

        for(auto it = diff.begin(); it != diff.end(); it++){

            it->second += cumSum;
            cumSum = it->second;

            int targetFreq = freq[it->first];
            int needConversion = it->second - targetFreq;

            int reqOper = min(needConversion,numOperations);
            result = max(result,targetFreq + reqOper);

        }

        return result;


    }
};