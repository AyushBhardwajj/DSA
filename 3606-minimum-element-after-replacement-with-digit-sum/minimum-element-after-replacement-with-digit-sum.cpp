class Solution {
public:
    int minElement(vector<int>& nums) {
        int mint = INT_MAX;

        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            int curr = 0;

            while(val>0){
                curr += val%10;
                val = val/10;
            }

            mint = min(mint,curr);
        }

        return mint;
    }
};