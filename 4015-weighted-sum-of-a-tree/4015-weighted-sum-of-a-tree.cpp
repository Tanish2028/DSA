class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        
        int n = parent.size();

        int height = 1;
        vector<int>depth(n);

        depth[0] = 1;

        for(int i = 0;i<n;i++){
            if(depth[i] != 0){
                height = max(height,depth[i]);
                continue;
            }

            int x = i;
            vector<int>path;

            while(depth[x] == 0){
                path.push_back(x);
                x = parent[x];
            }

            for(int j = path.size()-1;j>=0;j--){
                depth[path[j]] = depth[x] +1;
                x = path[j];
            }
            height = max(height,depth[path[0]]);
        }

        long long ans = 0;

        for(int i = 0;i<n;i++){

            ans += ((long long)nums[i]*(height - depth[i] + 1));
        }

        return ans;
    }
};