class Solution {
public:
    int secondsBetweenTimes(string s1, string s2) {
        

        int startHr = stoi(s1.substr(0,2));
        int startMin = stoi(s1.substr(3,2));
        int startSec = stoi(s1.substr(6,2));

        int endHr = stoi(s2.substr(0,2));
        int endMin = stoi(s2.substr(3,2));
        int endSec = stoi(s2.substr(6,2));

        int t1 = startHr*3600 + startMin*60 + startSec;
        int t2 = endHr*3600 + endMin*60 + endSec;

        if(t1>t2) return t1 - t2;

        return t2 - t1;
 

    }
};