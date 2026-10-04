class Solution {
public:
    bool solve(string &s,int ind,int open,vector<vector<int>> &dp){
        if(ind == s.length()){
            if(open == 0)return true;
            return false;
        }

        if(dp[ind][open]!=-1)return dp[ind][open];

        bool ans = false;

        if(s[ind]=='('){
            ans = ans || solve(s,ind+1,open+1,dp);
        }
        else if(s[ind]==')'){
            if(open==0)return false;
            ans = ans || solve(s,ind+1,open-1,dp);
        }

        else{
            ans = ans || solve(s,ind+1,open+1,dp);
            if(open!=0){
                ans = ans || solve(s,ind+1,open-1,dp);
            }

            ans = ans || solve(s,ind+1,open,dp);
        }

        if(ans == true)dp[ind][open]=1;
        else dp[ind][open] = 0;

        return ans;
    }
    
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,0,dp);
    }
};