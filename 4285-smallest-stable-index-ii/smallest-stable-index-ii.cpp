class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1)return 0;

        vector<int> mint(n,0);

        mint[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            mint[i] = min(mint[i+1],nums[i]);
        }

        int maxt = 0;

        for(int i=0;i<n;i++){
            maxt = max(maxt,nums[i]);

            if(maxt - mint[i]<=k)return i;
        }

        return -1;
    }
};