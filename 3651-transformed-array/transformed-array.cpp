class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> arr = nums;

        for(int i=0;i<n;i++){
            if(arr[i]>0){
                int ind = (i+nums[i])%n;
                arr[i] = nums[ind];
            }

            else if(arr[i]<0){
                int ind = (i+nums[i]+1000*n)%n;
                arr[i] = nums[ind];
            }
        }

        return arr;
    }
};