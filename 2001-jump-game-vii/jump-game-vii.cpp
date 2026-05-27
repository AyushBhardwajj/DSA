class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<long long> dp(n,0);

        dp[0] = 1ll;

        int start = 0,end = 0;
        int ind = minJump;
        long long tot = 0;

        while(ind<n){

            tot = tot + dp[end];
            while(ind-start > maxJump){
                tot-=dp[start];
                start++;
            }

            if(s[ind]=='0' && tot>0){
                dp[ind] = 1ll;
            }

            ind++;
            end++;
        }

        return dp[n-1]>0ll?true:false;
        
    }
};