class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxElement = *max_element(nums.begin(),nums.end());

        long long ans = 0;
        int start = 0;
        int maxFreq = 0;
        int n = nums.size();

        for(int end = 0;end<n;end++){
            if(nums[end] == maxElement){
                maxFreq++;
            }

            while(maxFreq == k){
                if(nums[start] == maxElement){
                    maxFreq--;
                }
                start++;
            }

            ans  = ans + start;
        }

        return ans;
    }
};