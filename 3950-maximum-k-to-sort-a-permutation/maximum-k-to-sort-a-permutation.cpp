class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr = nums;

        sort(nums.begin(),nums.end());

        if(arr == nums)return 0;

        int ans = pow(2,30)-1;

        for(int i=0;i<n;i++){
            if(arr[i]!=nums[i]){
                ans = ans&arr[i];
            }
        }

        return ans;


    }
};