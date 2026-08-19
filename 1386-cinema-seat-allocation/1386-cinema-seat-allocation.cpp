class Solution {
public:

    bool isAvailable(int key,unordered_map<int,unordered_set<int>>& mpp,int val){

        if(mpp[key].find(val) != mpp[key].end()){
            return false;
        }
        return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        

//         vector<vector<long long>>cinema(n+1,vector<long long>(11,0));

//         for(int i = 0;i<reservedSeats.size();i++){
//             cinema[reservedSeats[i][0]][reservedSeats[i][1]] = 1;
//         }
        
//         int group = 0;

//         for(int i = 1;i<=n;i++){
//             int count = 0;
//             for(int j = 2;j<10;j++){

//                 if((count == 0) && (j == 2 || j == 4 || j == 6)){

//                 }
//                 else if((count == 0) && (j != 2 && j != 4 && j != 6)){
//                     continue;
//                 }
                

//                 if(!cinema[i][j]){
//                     count++;

//                     if(count == 4){
//                         group++;
//                         count = 0;
//                     }
//                 }
//                 else{
//                     count = 0;
//                 }
//             }
//         }

//         // return group;
//     }
       
       unordered_map<int,unordered_set<int>>mpp;

       for(auto it:reservedSeats){
        mpp[it[0]].insert(it[1]);
       }

       int m = mpp.size();

       int result = 0;

       result += (n-m)*2;

       for(auto it:mpp){

        bool grp1 = isAvailable(it.first,mpp,2) && isAvailable(it.first,mpp,3) && isAvailable(it.first,mpp,4) && isAvailable(it.first,mpp,5);
        bool grp2 = isAvailable(it.first,mpp,4) && isAvailable(it.first,mpp,5) && isAvailable(it.first,mpp,6) && isAvailable(it.first,mpp,7);
        bool grp3 = isAvailable(it.first,mpp,6) && isAvailable(it.first,mpp,7) && isAvailable(it.first,mpp,8) && isAvailable(it.first,mpp,9);

        if(grp1 && grp3){
            result += 2;
        }
        else if(grp1 || grp2 || grp3){
            result += 1;
        }

       }
       return result;
    }
     
};