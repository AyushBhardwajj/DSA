class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> suff(n,0),preff(n,0);

        preff[0] = nums[0];
        suff[n-1] = nums[n-1];

        vector<int> ans(n,0);

        map<int,int> mp;

        for(int i=1;i<n;i++){
            preff[i] = max(preff[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            suff[i] = min(suff[i+1],nums[i]);
        }

        ans[n-1] = preff[n-1];
        mp[nums[n-1]] = preff[n-1];

        for(int i=n-2;i>=0;i--){
            ans[i] = preff[i];
            if(preff[i]>suff[i+1]){
                ans[i] = ans[i+1];
            }

        }

        return ans;

    }
};