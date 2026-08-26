class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.length();

        int l = 0;
        int r = 0;

        int ones = 0;

        vector<vector<int>> vec;

        int miniLen = INT_MAX;

        while (r < n) {

            if (s[r] == '1')
                ones++;

            if (ones == k) {

                while (s[l] == '0') {
                    l++;
                }

                int len = r - l + 1;

                if (len < miniLen) {
                    miniLen = len;
                    vec.clear();
                    vec.push_back({l, r});
                }
                else if (len == miniLen) {
                    vec.push_back({l, r});
                }
            }
            else {
                
                while (ones > k) {
                    if (s[l] == '1') {
                        ones--;
                    }
                    l++;
                }

                if (ones == k) {

                    while (s[l] == '0') {
                        l++;
                    }

                    int len = r - l + 1;

                    if (len < miniLen) {
                        miniLen = len;
                        vec.clear();
                        vec.push_back({l, r});
                    }
                    else if (len == miniLen) {
                        vec.push_back({l, r});
                    }    
                }
            }

            r++;
        }

        if (miniLen == INT_MAX)
            return "";

        vector<string> st;

        for (auto it : vec) {
            int l = it[0];
            int r = it[1];

            st.push_back(s.substr(l, r - l + 1));
        }

        sort(st.begin(), st.end());

        return st[0];
    }
};