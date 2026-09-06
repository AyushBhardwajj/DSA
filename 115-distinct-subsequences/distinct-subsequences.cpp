class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j>=t.length()){
            return 1;
        }

        if(i>=s.length())return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int take = 0,nottake=0;

        if(s[i]==t[j]){
            take = solve(s,t,i+1,j+1,dp);
        }

        nottake = solve(s,t,i+1,j,dp);

        return dp[i][j] = take+nottake;
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        if(n<m)return 0;

        vector<vector<int>> dp(n+2,vector<int>(m+2,-1));

        return solve(s,t,0,0,dp);

    }
};