class Solution {
public:
    long long dp[16][(1<<15)][16];

    long long solve(int ind,int mask,vector<int> &nums,int last){
        if(ind == nums.size())return 1;

        if(dp[ind][mask][last]!=-1)return dp[ind][mask][last];

        long long take = 0;
        long long mod =1e9+7;

        for(int j=0;j<nums.size();j++){
            if(mask&(1<<j))continue;

            int nmask = mask|(1<<j);

            long long curr = 0;

            if(last == 15){
                curr = solve(ind+1,nmask,nums,j);
            }

            else if(nums[last]%nums[j]==0 || nums[j]%nums[last]==0){
                curr = solve(ind+1,nmask,nums,j);
            }

            take = (take+curr)%mod;
        }

        return dp[ind][mask][last] = take;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();

        long long anst = 0;
        long long mod = 1e9+7;

        memset(dp,-1,sizeof(dp));
        anst = solve(0,0,nums,15)%mod;

        return (int)anst;
    }
};