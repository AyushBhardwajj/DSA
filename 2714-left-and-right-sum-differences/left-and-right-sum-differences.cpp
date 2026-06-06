class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightsum = accumulate(nums.begin(),nums.end(),0);
        int leftsum = 0;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            rightsum -= nums[i];
            int curr = abs(leftsum - rightsum);
            ans.push_back(curr);
            leftsum+=nums[i];
        }

        return ans;
    }
};