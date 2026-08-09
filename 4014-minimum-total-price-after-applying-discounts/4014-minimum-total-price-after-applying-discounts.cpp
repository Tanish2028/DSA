class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        
        int n1 = prices.size();
        int n2 = discounts.size();

        int n = min(n1,n2);

        double cost = 0.0;

        for(int i = 0;i<n;i++){
            
            int p = prices[i];
            int d = discounts[i];
            cost += ((double)p*(100 - d))/100;
        }

        if(n1 > n2){
            for(int i = n;i<n1;i++){
                cost += prices[i];
            }
        }

        return cost;

    }
};