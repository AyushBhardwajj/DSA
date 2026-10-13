class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]-0);
        }

        sort(nums.rbegin(),nums.rend());

        int cnt = (n+1)/2;

        long long sum = 0;

        for(int i=0;i<n;i++){
            long long crr = nums[i];
            if(i<cnt){
                sum += crr*crr;
            }
            else sum-= crr*crr;
        }

        return sum;
    }
};