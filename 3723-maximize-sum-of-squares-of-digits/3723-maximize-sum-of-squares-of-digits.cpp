class Solution {
public:
    
    string maxSumOfSquares(int num, int sum) {
        
        if(num <= 1 && sum <= 9){
            return to_string(sum);
        }

        if(num <= 1 && sum > 9){
            return "";
        }

        string ans = "";

        while(num>0){
            int dig = min(9,sum);

            ans += char('0' + dig);

            sum -= dig;
            num--;
        }

        if(sum > 0 || sum < 0){
            return "";
        }
        return ans;

    }
};