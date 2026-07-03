class Solution {
public:
    
    bool check(int val,  vector<vector<pair<int, int>>>& adj,long long k,vector<bool>& online,int n){

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        
        pq.push({0,0});
        vector<long long>dis(n,LLONG_MAX);
        dis[0] = 0;

        while(!pq.empty()){

            long long cost = pq.top().first;
            long long v = pq.top().second;
            pq.pop();
            
            if(cost > k) return false; 
            if(v == n-1) return true;
            
            if(dis[v] < cost) continue;
            for(auto it:adj[v]){
                if(it.second < val) continue;

                if(it.second + cost < dis[it.first] && online[it.first]){
                    dis[it.first] = it.second + cost;
                    pq.push({it.second + cost,it.first});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();
        
        vector<vector<pair<int, int>>> adj(n);

        int l = INT_MAX;
        int r = 0;

        for(auto it:edges){

            if(!online[it[0]] || !online[it[1]]) continue;

            adj[it[0]].push_back({it[1],it[2]});

            l = min(l,it[2]);
            r = max(r,it[2]);
        }
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(mid,adj,k,online,n)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }

        }

        return ans;  
    }
};