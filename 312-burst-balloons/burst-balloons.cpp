class Solution {
public:
    
    int solve(int l,int r,vector<int> &nums,vector<vector<int>> &dp){
        if(l>r)return 0;

        if(dp[l][r]!=-1)return dp[l][r];

        int ans = 0;

        for(int i=l;i<=r;i++){
            int curr = nums[l-1]*nums[i]*nums[r+1]+solve(l,i-1,nums,dp)+solve(i+1,r,nums,dp);

            ans = max(ans,curr);
        }

        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        return solve(1,n,nums,dp);
    }
};