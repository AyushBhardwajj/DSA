class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int ind = -1;
        int last = nums[n-1];
        int frst = nums[0];
        bool flag = true;

        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                flag = false;
            }

            if(!flag && last>frst)return false;
        }


        if(cnt>1)return false;
        return true;
    }
};