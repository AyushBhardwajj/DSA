class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long tot = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long sum = 0;
        long long ans = 1e15;

        for(int i=0;i<n;i++){
            long long need = 1ll*i*nums[i] - sum;
            sum+=nums[i];
            need += tot - sum - 1ll*(n-i-1)*nums[i];

            ans = min(ans,need);

        }

        return (int)ans;


    }
};