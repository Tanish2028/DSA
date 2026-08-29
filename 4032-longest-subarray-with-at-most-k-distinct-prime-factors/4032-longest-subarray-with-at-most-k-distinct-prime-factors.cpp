class Solution {
public:
    void getPrimeFactors(unordered_map<int,int>& mpp,int n){
        for(int i = 2;i*i<=n;i++){
            while(n%i == 0){
                mpp[i]++;
                n = n/i;
            }
        }
        if(n>1){
            mpp[n]++;
        }
    }
    void removePrimeFactors(unordered_map<int,int>& mpp,int n){
        for(int i = 2;i*i<=n;i++){
            while(n%i == 0){
                mpp[i]--;
                if(mpp[i] == 0){
                    mpp.erase(i);
                }
                n = n/i;
            }
        }

        if(n>1){
            mpp[n]--;
            if(mpp[n] == 0){
                    mpp.erase(n);
                }
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int,int>mpp;

        int l = 0;
        int r = 0;

        int maxi = INT_MIN;

        while(r<n){

            getPrimeFactors(mpp,nums[r]);

            if(mpp.size() <= k){
                int len = r - l + 1;
                maxi = max(maxi,len);
            }

            else{
                while(mpp.size() > k){
                    removePrimeFactors(mpp,nums[l]);
                    l++;
                }

                maxi = max(maxi,r-l+1);
            }
            r++;
            
        }

        return maxi;

    }
};