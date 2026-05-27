class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;

        int maxEle = *max_element(nums.begin(),nums.end());

        int start = 0,end = 0;
        int freq = 0;
        int n = nums.size();

        while(end<n){
            if(nums[end] == maxEle){
                freq++;
            }

            while(freq>=k){
                ans += n-end;
                if(nums[start]==maxEle)freq--;
                start++;
            }
            end++;
        }

        return ans;
    }
};