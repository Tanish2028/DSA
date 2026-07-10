class DisjointSet
{

    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        // size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // void UnionBySize(int u, int v)
    // {
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);

    //     if (size[ulp_u] < size[ulp_v])
    //     {
    //         parent[ulp_u] = ulp_v;
    //         size[ulp_v] += size[ulp_u];
    //     }
    //     else
    //     {
    //         parent[ulp_v] = ulp_u;
    //         size[ulp_u] += size[ulp_v];
    //     }
    // }
};




class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        
        
        int m = queries.size();
        
        DisjointSet ds(n);

        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff)
                ds.UnionByRank(i, i + 1);
}

        vector<bool>ans;

        for(auto it: queries){
            if(ds.findUPar(it[0]) != ds.findUPar(it[1])){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }






        // for(auto q: queries){
            // queue<int>pq;
            // int u = q[0];
            // int v = q[1];
            // vector<int>vis(n,0);
            // pq.push(u);
            
            // bool flag = true;

            // while(!pq.empty()){
            //     int node = pq.front();
            //     pq.pop();

            //     if(node == v){
            //         flag = false;
            //         break;
            //     }

            //     for(auto it:adj[node]){
            //         if(!vis[it]){
            //             vis[it] = 1;
            //             pq.push(it);
            //         }
            //     }
            // }

            // if(!flag){
            //     ans.push_back(true);
            // }
            // else{
            //     ans.push_back(false);
            // }
        // }


        return ans;

    }
};