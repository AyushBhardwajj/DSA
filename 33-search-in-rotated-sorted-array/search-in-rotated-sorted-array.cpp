class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target)return 0;
        int n = nums.size();
        if(nums[n-1] == target)return n-1;

        int start = 1,end = n-2;

        while(start<=end){
            int mid = (start+end)/2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[mid]>=nums[start]){
                if(target>=nums[start] && nums[mid]>=target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else{
                if(target>=nums[mid] && nums[end]>=target){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }

        return -1;
    }
};