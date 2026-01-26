class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        
        int andd = 0;
        int ans = 0;
        int curr = nums[0];

        for(int i=0;i<nums.size();i++){
            curr  = curr&nums[i];
            if(andd == 0){
                andd = nums[i];
            }

            andd = andd&nums[i];

            if(andd == 0){
                ans++;
            }
        }

        if(curr>0)return 1;
        return ans;
    }
};