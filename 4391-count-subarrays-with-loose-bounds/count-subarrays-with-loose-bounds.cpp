class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int start = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                long long len = i-start;
                ans += len*(len+1)/2;
                start = i+1;
            }
        }

        long long len = n-start;
         ans += len*(len+1)/2;

         return ans;
    }
};