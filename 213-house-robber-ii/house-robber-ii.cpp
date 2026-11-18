class Solution {
public:
    int solve(vector<int> &nums,int ind,int end,vector<int> &dp){
        if(ind > end)return 0;

        if(dp[ind]!=-1)return dp[ind];

        int take = 0,nottake = 0;

        take = nums[ind] + solve(nums,ind+2,end,dp);
        nottake = solve(nums,ind+1,end,dp);

        return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return nums[0];

        vector<int> d1(n,-1),d2(n,-1);

        int ans1 = solve(nums,0,n-2,d1);
        int ans2 = solve(nums,1,n-1,d2);

        return max(ans1,ans2);
    }
};