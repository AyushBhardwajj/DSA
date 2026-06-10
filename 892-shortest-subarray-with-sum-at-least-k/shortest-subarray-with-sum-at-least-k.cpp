class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       
        int n = nums.size();

        deque<int> dq;

        int ans = INT_MAX;

        vector<long long> cmSum(n,0);

        for(int i=0;i<n;i++){
            if(i==0){
                cmSum[i] = nums[i];
            }
            else{
                cmSum[i] = nums[i]+cmSum[i-1];
            }

            if(cmSum[i]>=k){
                ans = min(ans,i+1);
            }

            while(!dq.empty() && cmSum[i]-cmSum[dq.front()] >=k){
                ans = min(ans,i-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cmSum[i]<=cmSum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans==INT_MAX?-1:ans;

        
    }
};