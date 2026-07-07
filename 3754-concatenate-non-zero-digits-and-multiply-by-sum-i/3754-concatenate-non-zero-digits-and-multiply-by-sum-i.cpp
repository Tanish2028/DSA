class Solution {
public:
    long long getDigit(int n){
        long long val = 0;
        long long sum = 0;
        while(n > 0){
            if(n%10 != 0){
                sum += n%10;
                val = val*10 + n%10;
            }
            n = n/10;
        }
        long long ans = 0;
        while(val > 0){
            ans = ans*10 + val%10;
            val = val/10;
        }
        return ans*sum;
    }
    long long sumAndMultiply(int n) {
        
        long long num = getDigit(n);

        return num;
    }
};