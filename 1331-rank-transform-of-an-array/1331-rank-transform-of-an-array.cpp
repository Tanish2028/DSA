class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();

        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,vector<int>> mpp;

        vector<int>ans(n);
        int rank = 1;

        for(int i = 0;i<n;i++){
            pq.push(arr[i]);
            mpp[arr[i]].push_back(i);
        }

        while(!pq.empty()){
            int elem = pq.top();
            pq.pop();
          
            for(auto mp : mpp[elem]){
                ans[mp] = rank;
            }
            rank++;
            while(!pq.empty() && pq.top() == elem){
                pq.pop();
            }   
        }

        return ans;
    }
};