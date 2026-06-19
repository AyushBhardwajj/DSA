class Solution {
public:
    int solve(vector<int> &rods,int ind,int diff,vector<vector<int>> &dp){
        if(ind == rods.size()){
            if(diff == 5000)return 0;
            return -1e8;
        }

        if(dp[ind][diff]!=-1)return dp[ind][diff];

        int take1 = rods[ind]+solve(rods,ind+1,diff+rods[ind],dp);
        int take2 = solve(rods,ind+1,diff-rods[ind],dp);
        int take3 = solve(rods,ind+1,diff,dp);

        return dp[ind][diff] = max({take1,take2,take3});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n,vector<int>(10001,-1));

        return max(0,solve(rods,0,5000,dp));
        
    }
};