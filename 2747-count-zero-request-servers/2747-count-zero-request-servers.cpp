class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
        });
        vector<pair<int,int>>q;

        for(int i = 0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }

        sort(q.begin(),q.end());
        unordered_map<int,int>mpp;

        vector<int>ans(queries.size(),0);

        int l = 0;
        int r = 0;

        for(auto &it : q){

            int r1 = it.first - x;
            int r2 = it.first;
            int idx = it.second;

            while(r < logs.size() && logs[r][1] <= r2){
                mpp[logs[r][0]]++;
                r++;
            }

            while(l < r && logs[l][1] < r1){
                mpp[logs[l][0]]--;
                if(mpp[logs[l][0]] == 0){
                    mpp.erase(logs[l][0]);
                }
                l++;
            }

            ans[idx] = n - mpp.size();
        }

        return ans;
        
    }
};