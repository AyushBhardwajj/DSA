class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int i = 0,j = 0;

        int ans = 0;

        while(j<n){
            ans++;
            dp[i][j]=true;
            i++,j++;
        }

        i=0;j=1;

        while(j<n){
            if(s[i]==s[j]){
                ans++;
                dp[i][j] = true;
            }
            i++,j++;
        }

        i=0,j=2;

        while(j<n){
            i=0;
            int col = j;

            while(col<n){
                if(s[i] == s[col] && dp[i+1][col-1]==true){
                    ans++;
                    dp[i][col] = true;
                }
                i++,col++;
            }
            j++;
        }

        return ans;
    }
};