class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        priority_queue<int>pq;

        int n = nums.size();

        for(int i = 0;i<n;i++){
            pq.push(abs(nums[i]));
        }

        int alt = ceil((double)n/2);

        long long sum = 0;

        int count = 0;
        while(count < alt){
            int elem = pq.top();
            pq.pop();

            sum += ((long long)elem*elem);
            count++;
        }

        while(!pq.empty()){
            int elem = pq.top();
            pq.pop();

            sum -= ((long long)elem*elem);
        }

        return sum;
    }
};