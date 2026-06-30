class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1;
        int b = -1;
        int c = -1;
        int count = 0;

        for(int i = 0;i<s.length();i++){
            if(s[i] == 'a'){
                a = i;
            }
            else if( s[i] =='b'){
                b = i;
            }
            else{
                c = i;
            }
            if(a!=-1 && b!=-1 && c!=-1){
                count += 1 + min(a,min(b,c));
            }
        }
        return count;
        
    }
};