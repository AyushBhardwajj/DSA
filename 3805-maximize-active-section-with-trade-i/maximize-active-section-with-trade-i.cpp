class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        int n  = s.length();

        int maxAdjZeroGrp = 0;
        int prevZeroGrp = -1e9;

        int start = 0;

        int oneCnt = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '1')oneCnt++;
        }

        while(start < n){
            int end = start;

            while(end<n && s[start] == s[end]){
                end++;
            }

            int length = end-start;

            if(s[start] == '0'){
                maxAdjZeroGrp = max(maxAdjZeroGrp,prevZeroGrp+length);

                prevZeroGrp = length;
            }

            start = end;
        }

        int answer = oneCnt + maxAdjZeroGrp;

        return answer;

    }
};