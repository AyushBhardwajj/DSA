class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        string t = "1"+s+"1";

        int count = 0;
        char ch = '1';

        vector<int> freqCount;

        for(int i=0;i<t.length();i++){
            if(ch==t[i])count++;
            else{
                freqCount.push_back(count);
                count = 1;
                ch = t[i];
            }
        }

        freqCount.push_back(count);

        int n = freqCount.size();

        int ans = 0;

        for(int i=2;i<freqCount.size();i+=2){
            
            if(i<n-2){
                ans = max(ans,freqCount[i-1]+freqCount[i+1]);
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i]=='1')ans += 1;
        }

        return ans;
    }
};