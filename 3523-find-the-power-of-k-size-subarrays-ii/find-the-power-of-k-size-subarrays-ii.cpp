class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0,end = 0;

        vector<int> ans(n-k+1,-1);

        if(k==1){
            return nums;
        }


        for(int end = 1 ; end < n ; end++){
            if(nums[end]!=nums[end-1]+1){
                start = end;
            }

            else if(end-start+1 == k){
                ans[start] = nums[end];
                start++;
            }
        }

        return ans;
    }
};