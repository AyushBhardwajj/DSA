class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size();

        if(n==1)return false;

        for(int i=1;i<n-1;i++){
            if(nums[i]==i+1 && nums[i]==1+nums[i-1]){
                continue;
            }else{
                return false;
            }
        }

        if(nums[n-1] == n-1 && nums[n-1]==nums[n-2])return true;
        return false;
    }
};