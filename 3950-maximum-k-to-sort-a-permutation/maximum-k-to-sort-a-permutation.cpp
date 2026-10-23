class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans = pow(2,30)-1;
        bool flag = false;

        for(int i=0;i<n;i++){
            if(i!=nums[i]){
                ans = ans&nums[i];
                flag = true;
            }
        }

        if(flag)return ans;
        return 0;


    }
};