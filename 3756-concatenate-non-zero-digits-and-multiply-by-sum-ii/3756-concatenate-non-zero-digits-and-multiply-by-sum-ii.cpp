class Solution {
public:
int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n = queries.size();
        int m = s.length();


        vector<long long>digitSum(m,0);
        vector<long long>numUpto(m,0);
        vector<int>countInt(m,0);

        vector<long long>pow10(m+1,0);

        pow10[0] = 1;

        for(int i = 1;i<=m;i++){
            pow10[i] = (pow10[i-1]*10)%mod;
        }

        for(int i = 0;i<m;i++){

            if(i == 0){
                digitSum[i] = s[0] - '0';
                if(s[0] != '0'){
                    numUpto[i] = s[0] - '0';
                    countInt[i] = 1;
                }
                continue;
            }

            digitSum[i] = digitSum[i-1] + s[i] - '0';
            if(s[i] != '0'){
                numUpto[i] = (numUpto[i-1]*10 + s[i] - '0')%mod;
                countInt[i] = countInt[i-1] + 1;
            }
            else{
                numUpto[i] = numUpto[i-1];
                countInt[i] = countInt[i-1];
            }
            
        }
        
        vector<int>ans;

        for(auto it:queries){
            int l = it[0];
            int r = it[1];
            
            if(l-1 >= 0){
                long long sum = digitSum[r] - digitSum[l-1];
                long long diff = countInt[r] - countInt[l-1];
                long long val = (numUpto[r] - (numUpto[l-1] * pow10[diff]) % mod + mod) % mod;

                long long result = ((sum % mod) * (val % mod))%mod;
                ans.push_back(result);
            }
            else{
                long long sum = digitSum[r];
                long long diff = countInt[r];
                long long val = numUpto[r];

                long long result = ((sum % mod) * (val % mod))%mod;
                ans.push_back(result);
            }
            
        }

        return ans;
    }
};