class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> vec(3*limit+1,0);

        for(int i=0;i<n/2;i++){
            int a = min(nums[i],nums[n-1-i]);
            int b = max(nums[i],nums[n-1-i]);

            vec[2]+=2;
            vec[a+1]-=1;
            vec[a+b]-=1;
            vec[a+b+1]+=1;
            vec[b+limit+1]+=1;
        }

        int curr  =0;
        int ans = n;

        for(int i=2;i<=2*limit;i++){
            curr+=vec[i];
            ans = min(ans,curr);
        }

        return ans;


    }
};