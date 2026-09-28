class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        

        int n = nums.size();

        if(n == 0) return 0;

        unordered_set<int>st;

        for(int x:nums){
            st.insert(x);
        }

        int longest = 1;

        for(int x : st){
            if(st.count(x-1)){
                continue;
            }

            else{
                int val = x;
                int count = 1;

                while(st.find(val+1) != st.end()){
                    count++;
                    val++;
                }
                longest = max(longest,count);
            }
        }

        return longest;
    }
};