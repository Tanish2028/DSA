class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size(); 

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int minIndex = -1;
        int maxIndex = -1;

        for(int i = 0;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIndex = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                minIndex = i;
            }
        }

        int countF = 0;
        bool maxF = false;
        bool minF = false;

        for(int i = 0;i<n;i++){
            if(maxF && minF){
                break;
            }

            if(nums[i] == maxi){
                countF++;
                maxF = true;
            }
            else if(nums[i] == mini){
                countF++;
                minF = true;
            }
            else{
                countF++;
            }
        }

        int countB = 0;
        bool maxB = false;
        bool minB = false;

        for(int i = n-1;i>=0;i--){
            if(maxB && minB){
                break;
            }

            if(nums[i] == maxi){
                countB++;
                maxB = true;
            }
            else if(nums[i] == mini){
                countB++;
                minB = true;

            }
            else{
                countB++;
            }
        }

        int countFB = 0;

        int l = 0;
        int r = n-1;

        while(l<n){

            if(nums[l] == maxi || nums[l] == mini){
                countFB++;
                break;
            }
            else{
                countFB++;
            }
            l++;
        }

        while(r>=0){

            if(nums[r] == maxi || nums[r] == mini){
                countFB++;
                break;
            }
            else{
                countFB++;
            }
            r--;
        }

        return min(countF,min(countB,countFB));

        




        
    }
};