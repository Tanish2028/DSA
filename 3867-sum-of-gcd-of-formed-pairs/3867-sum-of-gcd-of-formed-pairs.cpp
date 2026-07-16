class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int>store(n,0);

        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){

            maxi = max(maxi,nums[i]);

            store[i] = gcd(maxi,nums[i]);
        }

        sort(store.begin(),store.end());

        int st = 0;
        int end = store.size() - 1;

        long long ans = 0;
        while(st < end){

            ans += gcd(store[st],store[end]);
            st++;
            end--;
        }

        return ans;
        
        
    }
};