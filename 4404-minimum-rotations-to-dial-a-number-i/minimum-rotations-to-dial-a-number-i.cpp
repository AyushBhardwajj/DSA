class Solution {
public:
    int minRotations(string s) {
        int n = s.length();

        int ans = 0;
        int prev = 0;

        for(int i=0;i<n;i++){
            int curr = s[i]-'0';
            int mint = abs(prev-curr);
            int sec = 10-prev + curr;
            int thr = prev + 10 -curr;

            ans += min({mint,sec,thr});

            //cout<<ans<<" ";

            prev = curr;
        }

        return ans;
    }
};