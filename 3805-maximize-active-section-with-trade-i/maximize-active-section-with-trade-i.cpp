class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int prevZeroGroup = -1e9;
        int currZeroGroup = -1e9;

        char ch = s[0];
        int ind = 0;
        int maxAdjZeroGroup = 0;
        int onecnt= 0;

        for(int i=0;i<n;i++){
            if(s[i]=='1')onecnt++;
            if(s[i]!=ch){
                if(ch == '0'){
                    prevZeroGroup = currZeroGroup;
                    currZeroGroup = i-ind;
                    maxAdjZeroGroup = max(maxAdjZeroGroup,prevZeroGroup+currZeroGroup);
                }
                ind = i;
                ch = s[i];
            }
        }

        if(ch == '0'){
            prevZeroGroup = currZeroGroup;
            currZeroGroup = n-ind;
            maxAdjZeroGroup = max(maxAdjZeroGroup,prevZeroGroup+currZeroGroup);
        }

        return onecnt+maxAdjZeroGroup;

    }
};