class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int ans=1;
        int ind = 0;

        for(int i=0;i<n;i++){
            dp[i][i] = true;
            if(i!=0 && s[i]==s[i-1]){
                dp[i-1][i] = true;
                ind = i-1;
                ans = 2;
            }
        }

        int i = 0,j=2;

        while(j<n){
            int col = j;
            int row = 0;

            while(col<n){
                if((s[row] == s[col]) && (dp[row+1][col-1] == true)){
                    dp[row][col] = true;
                    int len = col-row+1;
                    if(len>ans){
                        ans = len;
                        ind = row;
                    }
                }
                row++;
                col++;
            }
            j++;
        }

        return s.substr(ind,ans);
    }
};