class Solution {
public:
    int solve(vector<int> &nums,int divisor){
        long long sum = 0;

        for(int i=0;i<nums.size();i++){
            sum += (nums[i]+divisor-1)/divisor;
            if(sum>1e6)return sum;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1,high = *max_element(nums.begin(),nums.end()) + 1;

        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            int count = solve(nums,mid);

            if(count <= threshold){
                ans =  mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};