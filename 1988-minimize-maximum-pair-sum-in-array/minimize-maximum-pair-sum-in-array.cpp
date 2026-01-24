class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size();

        int start = nums[0]+nums[1],end = nums[n-1]+nums[n-2];
        int ans = end;

        while(start<=end){
            int mid = start + (end-start)/2;
            bool flag = true;

            int left = 0,right = n-1;
            while(left<right){
                int sum = nums[left]+nums[right];

                if(sum>mid){
                    flag = false;
                    break;
                }

                left++,right--;
            }

            if(flag){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return ans;
    }
};