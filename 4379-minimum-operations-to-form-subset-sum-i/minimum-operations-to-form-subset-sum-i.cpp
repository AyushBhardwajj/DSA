class Solution {
public:
    int dp[100][5001];
    int solve(int ind,vector<int>& nums,int sum){
        if(ind == nums.size()){
            if(sum == 0)return 0;
            return 1e7;
        }

        if(dp[ind][sum]!=-1)return dp[ind][sum];

        int nottake = solve(ind+1,nums,sum);
        int take = 1e7;

        for(int i=0;i<=12;i++){
            int curr = (nums[ind]*pow(2,i));
            if(curr<=sum){
                take = min(take,i+solve(ind+1,nums,sum-curr));
            }
            else break;
        }

        for(int j=12;j>=1;j--){

            int curr = (nums[ind])/(pow(2,j));
            if(curr<=sum && sum>0){
                take = min(take,j+solve(ind+1,nums,sum-curr));
            }
        }

        return dp[ind][sum] = min(take,nottake);
    }
    
    int minOperations(vector<int>& nums, int sum) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,nums,sum);
        if(ans>100)return -1;
        return ans;
    }
};