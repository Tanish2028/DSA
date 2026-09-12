class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        unordered_map<int,vector<int>>mpp;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        int count = 0;

        for(auto it:mpp){
            if(it.second.size() >= 3){
                int val = it.second[1] - it.second[0];
                bool flag = true;
                for(int i = 1;i<it.second.size()-1;i++){
                    if(it.second[i+1] - it.second[i] == val){
                        flag = false;
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    count++;
                }
            }
        }

        return count;


    }
};