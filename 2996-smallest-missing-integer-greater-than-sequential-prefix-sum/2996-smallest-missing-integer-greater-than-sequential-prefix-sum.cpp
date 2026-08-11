class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        vector<int>pref(n,0);

        set<int>st;

        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }

        pref[0] = nums[0];
        
        int val = nums[0];

        for(int i = 1;i<n;i++){
            if(nums[i] - nums[i-1] == 1){
                pref[i] = pref[i-1] + nums[i];
                val = pref[i];
            }
            else{
                break;
            }
        }

        // for(int i = 1;i<n;i++){

        //     if(nums[i] - nums[i-1] == 1){

        //         pref[i] = pref[i-1] + nums[i];
        //         len++;
        //         if(maxi<len){
        //             maxi = max(maxi,len);
        //             val = pref[i];
        //         }
        //     }
        //     else{
        //         pref[i] = nums[i];
        //         len = 0;
        //     }
        // }

        while(st.find(val) != st.end()){
            val++;
        }

        return val;


    }
};