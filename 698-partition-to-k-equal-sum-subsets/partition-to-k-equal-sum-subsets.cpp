class Solution {
public:
    
    bool solve(int mask, int currSum, int target, 
               vector<int> &nums, 
               vector<int> &dp) {
        
        if(mask == (1<<nums.size()) - 1)
            return true;   // all elements used
        
        if(dp[mask] != -1)
            return dp[mask];
        
        for(int j = 0; j < nums.size(); j++){
            
            if(mask & (1<<j)) continue;  // already used
            
            if(currSum + nums[j] <= target){
                
                int newMask = mask | (1<<j);
                
                int newSum = (currSum + nums[j]) % target;
                
                if(solve(newMask, newSum, target, nums, dp))
                    return dp[mask] = 1;
            }
        }
        
        return dp[mask] = 0;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int total = 0;
        for(int x : nums) total += x;
        
        if(total % k != 0) return false;
        
        int target = total / k;
        
        sort(nums.rbegin(), nums.rend());   // important optimization
        
        if(nums[0] > target) return false;
        
        vector<int> dp(1<<nums.size(), -1);
        
        return solve(0, 0, target, nums, dp);
    }
};
