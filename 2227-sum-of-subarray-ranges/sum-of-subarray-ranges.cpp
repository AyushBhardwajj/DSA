class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st1,st2;
        int n = nums.size();
        vector<int> pge(n),pse(n),nge(n),nse(n);

        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[i]>=nums[st1.top()]){
                st1.pop();
            }

            pge[i] = st1.empty()?-1:st1.top();
            st1.push(i);

            while(!st2.empty() && nums[i]<=nums[st2.top()]){
                st2.pop();
            }

            pse[i] = st2.empty()?-1:st2.top();
            st2.push(i);
        }

        while(!st1.empty()){
            st1.pop();
        }
        while(!st2.empty()){
            st2.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && nums[i]>nums[st1.top()]){
                st1.pop();
            }

            nge[i] = st1.empty()?n:st1.top();
            st1.push(i);

            while(!st2.empty() && nums[i]<nums[st2.top()]){
                st2.pop();
            }

            nse[i] = st2.empty()?n:st2.top();
            st2.push(i);
        }

        long long small = 0,great = 0;

        for(int i=0;i<n;i++){
            great += 1ll*nums[i]*(nge[i]-i)*(i-pge[i]);
            small += 1ll*nums[i]*(nse[i]-i)*(i-pse[i]);
        }

        long long ans = great-small;

        return ans;
    }
};