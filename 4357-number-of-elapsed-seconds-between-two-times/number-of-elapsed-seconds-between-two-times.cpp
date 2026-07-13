class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string h1 = "",h2 = "";

        h1.push_back(startTime[0]);
        h1.push_back(startTime[1]);

        h2.push_back(endTime[0]);
        h2.push_back(endTime[1]);

        int hrs = stoi(h2) - stoi(h1);

        string m1 = "",m2 = "";

        m1.push_back(startTime[3]);
        m1.push_back(startTime[4]);
        
        m2.push_back(endTime[3]);
        m2.push_back(endTime[4]);

        int min = stoi(m2) - stoi(m1);
        if(min<0){
            hrs--;
            min = min+60;
        }

        string s1 = "" ,s2 = "";

        s1.push_back(startTime[6]);
        s1.push_back(startTime[7]);

        s2.push_back(endTime[6]);
        s2.push_back(endTime[7]);

        int sec = stoi(s2)-stoi(s1);

        if(sec<0){
            min--;
            sec = sec+60;
        }

        int ans = hrs*60*60 + min*60 + sec;

        return ans;

        

        
    }
};