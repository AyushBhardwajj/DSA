class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        while(nums.size()>1){
            int ind = 0;
            int n = nums.size();
            vector<int> vec;
            int mint = 1e9;
            bool flag = true;

            for(int i=0;i<n-1;i++){
                if(mint>nums[i]+nums[i+1]){
                    mint = nums[i]+nums[i+1];
                    ind = i;
                }

                if(nums[i]>nums[i+1])flag = false;
            }

            if(flag){
                return ans;
            }

            for(int i=0;i<n;i++){
                if(i==ind){
                    vec.push_back(nums[i]+nums[i+1]);
                    i++;
                }
                else vec.push_back(nums[i]);
            }

            nums = vec;

            ans++;

        }

        return ans;
    }
};