class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxt = *max_element(nums.begin(),nums.end());
        int mint = *min_element(nums.begin(),nums.end());

        long long ans = 1ll*k*(maxt-mint);

        return ans;
    }
};