class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        if(n == 1)return nums;

        int prefix = 1;

        for(int i=1;i<n;i++){
            prefix = prefix*nums[i-1];
            ans[i] = prefix;
        }

        int suffix = 1;

        for(int i=n-2;i>=0;i--){
            suffix = suffix*nums[i+1];
            ans[i] = ans[i]*suffix;
        }

        return ans;
    }
};