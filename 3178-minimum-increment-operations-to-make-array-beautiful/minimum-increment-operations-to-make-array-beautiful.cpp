class Solution {
public:
    
    long long solve(int ind,vector<int> &nums,int k,vector<long long> &dp){
        int n = nums.size();
        if(ind+2 >= n)return 0;

        if(dp[ind]!=-1)return dp[ind];

        long long ans = 1e15;

        for(int i=ind;i<min(n,ind+3);i++){
            long long need = max(0,k-nums[i]);
            ans = min(ans,need+solve(i+1,nums,k,dp));
        }

        return dp[ind] = ans;
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> dp(n,-1);

        return solve(0,nums,k,dp);
    }
};