class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(101,0);

        int n = nums.size();

        for(int i=0;i<n;i++){
            int curr = 0;
            if(nums[i]%k == 0)curr = nums[i]/k;
            freq[curr]=1;
        }

        int ans = 101*k;

        for(int i=1;i<=100;i++){
            if(freq[i]==0)return i*k;
        }

        return ans;
    }
};