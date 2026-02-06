class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int n = nums.size();

        int left = 0,right = 0;

        int ans = 1e7;

        while(right<n){
            while(right<n && 1ll*nums[right]<=1ll*nums[left]*k){
                right++;
            }

            ans  = min(ans,left-0+n-right);

            while(right <n && 1ll*nums[right]>1ll*nums[left]*k){
                left++;
            }

            ans = min(ans,left-0+n-right);
        }

        return ans;
    }
};