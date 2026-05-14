class Solution {
public:
    void solve(int start,int end,int cnt,int sum,vector<int> &nums,vector<vector<int>> &dp){

        dp[cnt].push_back(sum);

        for(int i=start;i<end;i++){
            solve(i+1,end,cnt+1,sum+nums[i],nums,dp);
        }

        return;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();

        int k = n/2;

        int lsum = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> dp1(k+1);
        vector<vector<int>> dp2(k+1);

        solve(0,k,0,0,nums,dp1);
        solve(k,n,0,0,nums,dp2);

        int ans = INT_MAX;

        for(int i = 0;i<dp2.size();i++){
            sort(dp2[i].begin(),dp2[i].end());
        }

        for(int i=0;i<=k;i++){
            for(int j=0;j<dp1[i].size();j++){
                int curr = dp1[i][j];
                int target = (lsum - 2*curr)/2;

                auto it = lower_bound(dp2[k-i].begin(),dp2[k-i].end(),target);

                if(it!=dp2[k-i].end()){
                    ans = min(ans,abs(lsum - 2*(curr+*it)));
                }

                if(it!=dp2[k-i].begin()){
                    it--;
                    ans = min(ans,abs(lsum - 2*(curr+*it)));
                }
            }
        }

        return ans;

    }
};