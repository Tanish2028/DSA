class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(true){
            int val = n;
            int prod = 1;
            while(val > 0){
                prod *= (val%10);
                val = val/10;
            }
            if(prod % t == 0) return n;
            n = n+1;
        }

        return 0;
    }
};