class Solution {
public:
    void solve(int start,int end,int tot,int cnt,vector<int> &nums,vector<vector<int>> &dp){
        if(start == end){
            dp[cnt].push_back(tot);
            return;
        }

        solve(start+1,end,tot+nums[start],cnt+1,nums,dp);
        solve(start+1,end,tot,cnt,nums,dp);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n/2;

        int sum = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> dp1(k+1);
        vector<vector<int>> dp2(k+1);

        solve(0,k,0,0,nums,dp1);
        solve(k,n,0,0,nums,dp2);

        for(int i=0;i<=k;i++){
            sort(dp2[i].begin(),dp2[i].end());
        }

        int ans = INT_MAX;

        for(int i=0;i<=k;i++){
            for(int j=0;j<dp1[i].size();j++){
                int need = sum/2  - dp1[i][j];

                auto it = lower_bound(dp2[k-i].begin(),dp2[k-i].end(),need);

                if(it!=dp2[k-i].end()){
                    int val = *it;
                    ans = min(ans,abs(sum - 2*(dp1[i][j] + val)));
                }


                if(it != dp2[k-i].begin()){
                    it--;
                    int val = *it;
                    ans = min(ans,abs(sum - 2*(dp1[i][j] + val)));
                }
            }
        }

        return ans;

    }
};