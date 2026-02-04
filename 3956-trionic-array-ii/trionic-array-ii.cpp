class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        
        vector<int> arr;

        int n = nums.size();

        for(int i=1;i<n-2;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
                arr.push_back(i);
            }
        }

        long long ans = -1e15;

        for(int i=0;i<arr.size();i++){
            long long curr = nums[arr[i]-1];
            int start = arr[i]-2;
            int cnt = 1;

            while(start>=0 && nums[start]>0 && nums[start]<nums[start+1]){
                curr+=nums[start];
                cnt++;
                start--;
            }

            start = arr[i];

            cnt = 0;

            while(start<n-1 && nums[start]>nums[start+1]){
                curr+=nums[start];
                cnt++;
                start++;
            }

            curr+=nums[start];
            start++;

            cnt = 0;

            while(start<n && nums[start]>nums[start-1]){
                curr+=nums[start];
                ans = max(ans,curr);
                cnt++;
                start++;
            }

            if(cnt!=0){
                ans = max(ans,curr);
            }

        }

        return ans;
    }
};