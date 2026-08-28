class Solution {
public:
    
    int func(vector<string>& arr, int idx,string temp,int n){
        if(idx == n){
            return 0;
        }
        
        int include = 0;
        int exclude = 0;

        if(hasDuplicate(arr[idx],temp)){
            exclude = 0 + func(arr,idx+1,temp,n);
        }
        else{
           exclude = 0 + func(arr,idx+1,temp,n);
           include = arr[idx].length() + func(arr,idx+1,temp+arr[idx],n);   
        }

        return max(include,exclude);
    }
    bool hasDuplicate(string s1,string s2){
        vector<int>count(26,0);

        for(int i = 0;i<s1.length();i++){
            if(count[s1[i] - 'a'] > 0) return true;
            count[s1[i] - 'a']++;
        }

        for(int i = 0;i<s2.length();i++){
            if(count[s2[i] - 'a'] > 0) return true;
        }
        return false;
    }

   
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();

        string temp = "";

        return func(arr,0,temp,n);


    }
};