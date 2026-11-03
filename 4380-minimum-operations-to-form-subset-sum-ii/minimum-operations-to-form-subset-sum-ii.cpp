class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums,int sum,int ind){
        if(ind == nums.size()){
            if(sum == 0)return 0;
            return 1e8;
        }

        if(dp[ind][sum]!=-1)return dp[ind][sum];

        int take = 1e8,nottake = 1e8;

        nottake = solve(nums,sum,ind+1);

        int numt = nums[ind];
        int cnt = 0;

        while(numt>0){
            int dup = numt;
            int mul = 1;
            while(dup<=sum){
                take = min(take,cnt+mul-1+solve(nums,sum-dup,ind+1));
                dup = numt*pow(2,mul);
                mul++;
            }
            numt = numt/2;
            cnt++;
        }

        return dp[ind][sum] = min(take,nottake);
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        dp.resize(n,vector<int>(5001,-1));
        int ans =  solve(nums,sum,0);
        return ans>=1e8?-1:ans;
    }
};