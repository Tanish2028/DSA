class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        string t = '1' + s + '1';

        int len = t.length();
        int countOne = 0;
        for(int i = 1;i<len-1;i++){
            if(t[i] == '1'){
                countOne++;
            }
        }
        int ans = countOne;
        int i = 1;
        while(i<len-1){
            if(t[i] == '0'){
                i++;
                continue;
            }

            int l = i;
            while(i<len && t[i] == '1'){
                i++;
            }
            int r = i-1;
            int x = r+1;
            while(x<len && t[x] == '0') x++;
            int y = l-1;
            while(y>=0 && t[y] == '0') y--;

            if(x != r+1 && y != l-1){
                int val1 = x - r - 1;
                int val2 = l - y - 1;
                ans = max(ans,countOne + val1 + val2);
            }

        }

        return ans;


    }
};