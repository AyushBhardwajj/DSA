class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(),nums.end());

        int ans1 = 1,ans2 = 1;

        int n = nums.size();

        for(int i=0;i<n;i++){
            ans1 = ans1*nums[i];
            ans2 = ans2*nums[n-1-i];

            ans = max({ans1,ans2,ans});

            if(ans1==0)ans1 = 1;
            if(ans2==0)ans2 = 1;
        }

        return ans;

    }
};