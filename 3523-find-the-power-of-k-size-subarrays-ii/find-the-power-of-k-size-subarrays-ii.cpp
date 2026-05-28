class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0,end = 0;
        vector<int> dp(n);

        dp[0] = 1;

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                dp[i] = 1+dp[i-1];
            }
            else dp[i] = 1;
        }

        vector<int> fans;

        for(int i=k-1;i<n;i++){
            if(dp[i]>=k){
                fans.push_back(nums[i]);
            }
            else fans.push_back(-1);
        }

        return fans;
    }
};