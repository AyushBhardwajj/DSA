class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(4,1));

        int ans = 1;

        for(int i=1;i<n;i++){
            if(i==1){
                if(nums[i]>nums[i-1]){
                    dp[i+1][1] = 1+dp[i][0];
                    dp[i+1][3] = 1+dp[i][2];
                    ans = max(ans,dp[i+1][1]);
                    ans = max(ans,dp[i+1][3]);
                }
                if(nums[i-1]>nums[i]){
                    dp[i+1][0] = 1+dp[i][1];
                    dp[i+1][2] = 1+dp[i][3];
                    ans = max(ans,dp[i+1][0]);
                    ans = max(ans,dp[i+1][2]);
                }
            }
            else{
                if(nums[i]>nums[i-1]){
                    dp[i+1][1] = 1+dp[i][0];
                    dp[i+1][3] = 1+dp[i][2];
                    ans = max(ans,dp[i+1][1]);
                    ans = max(ans,dp[i+1][3]);
                }
                if(nums[i-1]>nums[i]){
                    dp[i+1][0] = 1+dp[i][1];
                    dp[i+1][2] = 1+dp[i][3];
                    ans = max(ans,dp[i+1][0]);
                    ans = max(ans,dp[i+1][2]);
                }

                if(nums[i]>nums[i-2]){
                    dp[i+1][3] = max(dp[i+1][3],1+dp[i-1][0]);
                    ans = max(ans,dp[i+1][3]);
                }

                if(nums[i-2]>nums[i]){
                    dp[i+1][2] = max(dp[i+1][2],1+dp[i-1][1]);
                    ans = max(ans,dp[i+1][2]);
                }
            }
        }

        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<4;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     //cout<<"\n";
        // }

        return ans;
    }
};