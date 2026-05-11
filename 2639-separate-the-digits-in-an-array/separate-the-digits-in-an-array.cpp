class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();

        for(int i=n-1;i>=0;i--){
            int val = nums[i];

            while(val){
                ans.push_back(val%10);
                val = val/10;
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};