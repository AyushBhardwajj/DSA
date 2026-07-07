class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n),ans(n);

        if(n == 1)return nums;

        prefix[0] = nums[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i];
        }

        int product = 1;

        for(int i=n-1;i>0;i--){
            ans[i] = product*prefix[i-1];
            product = product*nums[i];
        }

        ans[0] = product;

        return ans;
    }
};